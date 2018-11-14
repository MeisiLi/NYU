#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda.h>
#include <stdbool.h>

// If want to print the number array and get the max of sequential, then let the ISSQUENTIAL be 'true'
#define ISSQUENTIAL false   
// If want to check the answer of GPU method is correct or not, let the CHECKANS be 'true'
#define CHECKANS true
#define THREAD 1024

// Global functions
unsigned int getmax(unsigned int *, unsigned int);
unsigned int getmaxcu(unsigned int *, unsigned int);
__global__ void getMaximum(unsigned int num[], unsigned int size);

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
        for(int i = 0; i < size; i++)   printf("%d ", numbers[i]);  // This is the array print out
        printf("\n (Sequential) The maximum number in the array is: %u\n", 
                getmax(numbers, size));
    }

    // GPU method
    printf(" The maximum number in the array is: %u\n", 
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

/*
    input: pointer to an array of unsigned int
        number of elements in the array
    output: the maxumum number of the array
 */
unsigned int getmaxcu(unsigned int number[], unsigned int n)
{
    // setup GPU
    int deviceId = 0;
    cudaError_t error = cudaGetDevice(&deviceId);
    cudaSetDevice(1);

    // error handling
    if( error != cudaSuccess )
    {
        printf("CUDA error: %s\n", cudaGetErrorString(error));
        exit(-1);
    }

    unsigned int size = ceil(n / THREAD);
    unsigned int maxval = 0;
    unsigned int threads = n;
    if(n > THREAD)  threads = THREAD;

    unsigned int blocks = (n + threads - 1) / threads;
    unsigned int *num, *answer;
    unsigned int lenNum = n * sizeof(unsigned int);
    unsigned int lenBlock = blocks * sizeof(unsigned int);

    // Transfer to device
    cudaMalloc((void **)&num, lenNum);
    cudaMemcpy(num, number, lenNum, cudaMemcpyHostToDevice);

    // Kernal invocation for 
    cudaDeviceSynchronize();
    getMaximum<<<1, 1>>>(num, n);

    // Transfer to host
    answer = (unsigned int *)malloc(lenBlock);
    cudaMemcpy(answer, num, lenBlock, cudaMemcpyDeviceToHost);

    maxval = answer[0];

    // Free
    cudaFree(num);
    free(answer);
    // All data to be flushed
    cudaDeviceReset();

    if( CHECKANS )
    {
        unsigned int seq = getmax(number, n);
        if(seq != maxval)
            printf("The answer is incorrect: (sequential)%d (GPU)%d\n", seq, maxval);
    }
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
