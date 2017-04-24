#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

#include "IntList.h"
#include "test.h"
#include "sorting.h"

#define MAX 1000
int main() {
	IntList list, save;
	/*int i;*/
	int bubbleCount, selectionCount, quickCount;
	time_t t1, t2;
	int bubbleTime, selectionTime, quickTime;

	srand((unsigned) time(NULL));

	list = createIntList();
	initialiseIntList(&list);
	initialiseIntList(&save);
	

/*
	for(i = 0; i < MAX; i++) {
		if(rand()%2)
			insertIntList(&list, rand() % 20);
		else
			removeIntList(&list, rand() % 20);
	}
*/
	fillIntList(&list);
	copyIntList(&list, &save);

	time(&t1);
	bubbleCount = bubbleSort(&list);
	bubbleTime = (int)(time(&t2) - t1);
	copyIntList(&save, &list);
	time(&t1);
	selectionCount = selectionSort(&list);
	selectionTime = (int)(time(&t2) - t1);
	copyIntList(&save, &list);
	time(&t1);
	quickCount = quickSort(&list);
	quickTime = (int)(time(&t2) - t1);

	displayIntList(&list);

	printf("bubble sort: \t%d\t\t%ds\n", bubbleCount, bubbleTime);
	printf("selection sort: \t%d\t%ds\n", selectionCount, selectionTime);
	printf("quick sort: \t%d\t\t%ds\n", quickCount, quickTime);
	return EXIT_SUCCESS;
}





















