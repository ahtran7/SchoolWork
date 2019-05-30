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
	//Check current ID
	if (!pthread_equal(CurrentID, pthread_self()) && counter[pthread_self() - 1] == 0) {
		printf("Not My Turn! %d\n", pthread_self());
	}

	while (!pthread_equal(CurrentID, pthread_self())) {

	}

	//Thread gets turn 
	if (pthread_equal(CurrentID, pthread_self())) {

		printf("My Turn! %d\n", pthread_self());
		counter[pthread_self() - 1] += 1;

		//increment thread ID
		CurrentID += 1;

		if (CurrentID == 5)
			CurrentID = 1;
	}

	//print for ten times

	while (counter[pthread_self() - 1] <= 10) {

		startThread(NULL);

	}

	return NULL;

}

int main(int argc, char *argv[]) {
	pthread_t tid;

	//start creating and executing threads

	for (int i = 1; i < 5; i++) {
		pthread_create(&tid, NULL, &startThread, NULL);
		pthread_join(tid, NULL);
	}

	pthread_exit(NULL);

	return 0;
}