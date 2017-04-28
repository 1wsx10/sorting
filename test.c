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
	clock_t t1;
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

	t1 = clock();
	bubbleCount = bubbleSort(&list);
	bubbleTime = (clock() - t1);
	copyIntList(&save, &list);
	t1 = clock();
	selectionCount = selectionSort(&list);
	selectionTime = (clock() - t1);
	copyIntList(&save, &list);
	t1 = clock();
	quickCount = quickSort(&list);
	quickTime = (clock() - t1);

	displayIntList(&list);

	printf("bubble sort: \t		%d\t%d\n", bubbleCount, bubbleTime);
	printf("selection sort: \t	%d\t%d\n", selectionCount, selectionTime);
	printf("quick sort: \t		%d\t%d\n", quickCount, quickTime);
	return EXIT_SUCCESS;
}





















