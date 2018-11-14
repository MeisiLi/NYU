#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda.h>
#include <stdbool.h>

#define ISSQUENTIAL false
#define THREAD 1024

unsigned int getmax(unsigned int *, unsigned int);
unsigned int getmaxcu(unsigned int *, unsigned int);
__global__ void getMaximum(unsigned int num[], unsigned int size);
__global__ void getMax(unsigned int num[], unsigned int size, unsigned int ans[]);

int main(int argc, char *argv[])
{
    unsigned int size = 0;  // The size of the array
    unsigned int i;  // loop index
    unsigned int * numbers; //pointer to the array

    if(argc !=2)
    {
        printf("usage: maxseq num\n");
        printf("num = size of the array\n");
        exit(1);
    }

    size = atol(argv[1]);

    numbers = (unsigned int *)malloc(size * sizeof(unsigned int));
    if( !numbers )
    {
        printf("Unable to allocate mem for an array of size %u\n", size);
        exit(1);
    }    

    srand(time(NULL)); // setting a seed for the random number generator
    // Fill-up the array with random numbers from 0 to size-1 
    for( i = 0; i < size; i++)
        numbers[i] = rand()  % size;    

    if( ISSQUENTIAL ){
        for(int i = 0; i < size; i++)   printf("%d ", numbers[i]);
        printf("\n (Sequential) The maximum number in the array is: %u\n", 
                getmax(numbers, size));
    }

    
    printf(" (GPU) The maximum number in the array is: %u\n", 
            getmaxcu(numbers, size));

    free(numbers);
    exit(0);
}


/*
input: pointer to an array of long int
number of elements in the array
output: the maximum number of the array
 */
unsigned int getmax(unsigned int num[], unsigned int size)
{
    unsigned int i;
    unsigned int max = num[0];

    for(i = 1; i < size; i++)
        if(num[i] > max)
            max = num[i];

    return( max );

}

unsigned int getmaxcu(unsigned int number[], unsigned int n)
{
    // setup GPU
    int deviceId = 0;
    cudaError_t error = cudaGetDevice(&deviceId);;

    cudaSetDevice(1);

    // error handling
    if( error != cudaSuccess )
    {
        printf("CUDA error: %s\n", cudaGetErrorString(error));
        exit(-1);
    }

    unsigned int size = ceil(n / THREAD);
    unsigned int maxval, threads;
    if(n > THREAD)  threads = THREAD;
    else    threads = n;

    unsigned int blocks = (n + threads - 1) / threads;
    unsigned int *result, *num, *answer;
    unsigned int len = n * sizeof(unsigned int);
    unsigned int lenBlock = blocks * sizeof(unsigned int);

    // Transfer to device
    cudaMalloc((void **)&num, len);
    cudaMemcpy(num, number, len, 
        cudaMemcpyHostToDevice);

    cudaMalloc((void **)&result, len);
    //printf("len: %d lenBlock: %d\n", len, lenBlock);
    cudaMemcpy(result, number, len, cudaMemcpyHostToDevice);

    // Kernal invocation for 
    cudaDeviceSynchronize();
    getMaximum<<<1, 1>>>(num, n);

    // Transfer to host
    answer = (unsigned int *)malloc(lenBlock);
    cudaMemcpy(answer, num, lenBlock, 
        cudaMemcpyDeviceToHost);

    maxval = answer[0];

    cudaFree(num);
    cudaFree(result);
    free(answer);

    cudaDeviceReset();

    return maxval;
}

__global__ void getMaximum(unsigned int num[], unsigned int size)
{
    for(int i=0; i<size; i++)
    {
        if(num[i] > num[0])
            num[0] = num[i];
    }
}

__global__ void getMax(unsigned int num[], unsigned int size, unsigned int ans[])
{
    __shared__ unsigned int shared[THREAD];

    // global thread id 
    int grid = blockIdx.x * blockDim.x + threadIdx.x;
    
    shared[threadIdx.x] = num[grid];
    if( threadIdx.x >= size )   shared[threadIdx.x] = 0;

    __syncthreads();

    ans[threadIdx.x] = shared[grid];

    printf("grid: %d, threadIdx.x: %d blockDim.x: %d\n", 
        grid, threadIdx.x, blockDim.x);

    for(unsigned int s = blockDim.x; s > 0; s = s / 2)
    {
        int mid = s / 2;
        if(threadIdx.x < mid)
            if(ans[threadIdx.x] < ans[threadIdx.x + mid])
                ans[threadIdx.x] = ans[threadIdx.x + mid];
        __syncthreads();
    }

    /*
    if(threadIdx.x == 0)
        printf("block: %d\n", ans[0]);
    */

    ans[blockIdx.x] = shared[0];
}
