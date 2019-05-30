#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*I have not received unauthorized aid on this assignment. I understand the answers that I have
submitted. The answers submitted have not been directly copied from another source, but
instead are written in my own words.*/

//Create global variables
int CurrentID = 1;
static int counter[] = { 0,0,0,0 };

void* threadStart(void *arg) {
	int* ID = (int *) arg;
	
	//Check current ID
	if (!CurrentID == ID && counter[ID - 1] == 0) {
		printf("Not My Turn! %d\n", ID);
	}

	while (!CurrentID == ID) {

	}

	//Thread gets turn 
	if (CurrentID == ID) {

		printf("My Turn! %d\n", ID);
		counter[ID - 1] += 1;

		//increment thread ID
		CurrentID += 1;

		if (CurrentID == 5)
			CurrentID = 1;
	}

	//print for ten times

	while (ID - 1] <= 10) {

		startThread(NULL);

	}

	return NULL;

}

int main(int argc, char *argv[]) {
	int thread_number = 5;
	pthread_t threads[thread_number];
	pthread_t tid[thread_number];
	
	for(int i = 1; i < thread_number; i++) {
		tid[i] = i;
	}	

	//start creating and executing threads

	for (int i = 1; i < 5; i++) {
		pthread_create(&threads[i], NULL, startThread, tid[i]);
		pthread_join(threads[i], NULL);
	}

	pthread_exit(NULL);

	return 0;
}
