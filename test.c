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
	int bubbleCount, selectionCount, quickCount, mergeCount;

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

	bubbleCount = bubbleSort(&list);
	copyIntList(&save, &list);
	selectionCount = selectionSort(&list);
	copyIntList(&save, &list);
	quickCount = quickSort(&list);
	copyIntList(&save, &list);
	mergeCount = mergeSort(&list);

	displayIntList(&list);

	printf("bubble sort: \t%d\n", bubbleCount);
	printf("selection sort: \t%d\n", selectionCount);
	printf("quick sort: \t%d\n", quickCount);
	printf("merge sort: \t%d\n", mergeCount);
	return EXIT_SUCCESS;
}





















