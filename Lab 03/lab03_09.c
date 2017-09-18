#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

struct threadElements{
	int thread_id;
	int sum;
	int divide;
};

void *Print(void *threadArg)
{

	struct threadElements *myThread;

	int threadId;
	int sum;
	int divide;
	
	myThread = (struct threadElements *) threadArg;
	
	threadId = myThread->thread_id;
	sum = myThread->sum;
	divide = myThread->divide;
	
	printf("It's me, thread #%d. The sum is %d. The divide is %d\n", threadId, sum, divide);
	pthread_exit(NULL);
}




struct threadElements thread_data_array[NUM_THREADS];

int main (int argh, char *argv[])
{
	pthread_t threads[NUM_THREADS];

	int rc;
	int t;
	for(t=0; t<NUM_THREADS; t++){
		printf("In main: creating thread %d\n", t);
		
		thread_data_array[t].thread_id = t;
		
		
		int i = rand() % 100;
		int j = rand() % 100;
		int sum = i + j;
		int divide = i / j;
		
		thread_data_array[t].sum = sum;
		thread_data_array[t].divide = divide;
		
		
		rc = pthread_create(&threads[t], NULL, Print,(void *) &thread_data_array[t]);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	
/* Last thing that main() should do */
	pthread_exit(NULL);
}
