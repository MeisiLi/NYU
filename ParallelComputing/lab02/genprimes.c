#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <omp.h>

/*** Skeleton for Lab 2 ***/

/***** Globals ******/
int *x;       /* The numbers from 2 to num */
bool *isPrime;  /* The flat of numbers is prime from 2 to num */
int *primeNum;  /* The numbers is prime from 2 to num */
int num = 0;    /* 2 .. num */
int endNum;     /* The floor of (num+1)/2 */
int countPrime; /* Index in primeNum array */


/****** Function declarations */
void get_input();  /* Read input from file */

/********************************/

/* Function definitions: functions are ordered alphabetically ****/
/*****************************************************************/
void parallel(int numOfThread);


/******************************************************/
/* After this function returns:
 * x[] will contain 2 to num-2
 * isPrime[] is the mark for the current number is a prime number
 * num will have the largest number
 */
void get_input()
{
    int i,j;  

    x = (int *) malloc((num) * sizeof(int));
    if( !x)
    {
        printf("Cannot allocate x!\n");
        exit(1);
    }

    for(i = 0; i < num; i++){
        x[i] = i;
    }

    isPrime = (bool *) malloc(num * sizeof(bool));
    if( !isPrime)
    {
        printf("Cannot allocate isPrime!\n");
        exit(1);
    }
    for(j = 0; j < num; j++){
        isPrime[j] = true;
    }
}

/* 
 * parallel function
 * numOfThread: total threads
 * preNum: current prime number
 * currNum: the numbers that can divide by preNum
 */
void parallel(int numOfThread){
    int preNum;
    for(preNum = 2; preNum < num; preNum++){
        if(isPrime[preNum]){
            #pragma omp parallel num_threads(numOfThread)
            {
                int currNum;
                #pragma omp parallel for
                for(currNum = 2*preNum; currNum < num; currNum += preNum){
                    isPrime[currNum] = false;
                }
            }
        }
    }
}

/************************************************************/


int main(int argc, char *argv[])
{
    double tstart = 0.0, ttaken;
    int i;
    FILE * fp;
    char output[100] = "";

    if( argc != 3)
    {
        printf("Usage: ./genprime <number> <num_threads>\n");
        exit(1);
    }

    /* Read the input and fill the global data structure above */ 
    num = atoi(argv[1]);
    endNum = (num + 1)/2;
    get_input();
    int numOfThreads = atoi(argv[2]);
    
    tstart = omp_get_wtime();
    parallel( numOfThreads );
    
    int thread_rank = omp_get_thread_num();
    if( thread_rank == 0 ){
        ttaken = omp_get_wtime()-tstart;
        printf("Time take for the main part:%f\n", ttaken); 
    }

    /* Writing results to file */
    sprintf(output,"%d.sol",num);
    fp = fopen(output,"w");
    if(!fp)
    {
        printf("Cannot create the file %s\n", output);
        exit(1);
    }

    int rank = 0, pre = 2;
    for( i = 2; i <= num; i++){
        if( isPrime[i]){
            rank++;
            fprintf(fp, "%d, %d, %d\n", rank, i, i-pre);
            pre = i;
        }
    }

    fclose(fp);

    exit(0);

}
