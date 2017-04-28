#include <stdio.h>
#include <string.h>
#include "sorting.h"

void genericSwap(void* a, void* b, size_t len) {
	unsigned char *p = a, *q = b, tmp;
	size_t i;
	for(i = 0; i < len; i++) {
		tmp = p[i];
		p[i] = q[i];
		q[i] = tmp;
	}
}

void swapInt(int *a, int *b) {
	int tmp = *a;
	if(a == b)
		return;
	*a = *b;
	*b = tmp;
}

int bubbleSort(IntList *list) {
	int i, notSorted, placeHolder, count;
	
	count = 0;
	do {
		notSorted = 0;
		for(i = 0; i < list->size - 1; i++) {
			count++;
			if(list->list[i] > list->list[i+1]) {
				placeHolder = list->list[i];
				list->list[i] = list->list[i+1];
				list->list[i+1] = placeHolder;
				notSorted = 1;
			}
		}
	} while(notSorted);
	return count;
}

/* (20*(20+1))/2 */
int selectionSort(IntList * list) {
	int i, j, iMin;
	int count = 0;

	for(i = 0; i < list->size; i++) {
		iMin = i;
		for(j = i; j < list->size; j++) {
			count++;
			if(list->list[j] < list->list[iMin]) {
				iMin = j;
			}
		}
		swapInt(&list->list[i], &list->list[iMin]);
	}
	return count;
}

/* returns pivot index */
int partition(IntList * list, int lo, int hi) {
	int pivot = hi;
	int wall, j;
	
	wall = lo;
	for(j = lo; j <= hi; j++) {
		if(j == pivot)
			break;
		if(list->list[j] <= list->list[pivot]) {
			swapInt(&list->list[wall], &list->list[j]);
			wall++;
		}
	}
	swapInt(&list->list[wall], &list->list[pivot]);
	return wall;
}

int r_quickSort(IntList * list, int lo, int hi) {
	int part, count;

	count = 1;
	if(lo < hi) {
		part = partition(list, lo, hi);
		count += r_quickSort(list, lo, part-1);
		count += r_quickSort(list, part+1,hi);
	}
	return count;
}


int quickSort(IntList * list) {
	return r_quickSort(list, 0, list->size-1);
}

typedef struct iListArr {
	IntList list[INTLIST_SIZE];
	int size;
} IListArr;

IListArr createIListArr() {
	IListArr list;
	return list;
}

void initIListArr(IListArr * list) {
	/*
	int i;
	for(i = 0; i < INTLIST_SIZE; i++) {
		memset(&list->list[i], '\0', sizeof(IntList));
	}
	*/
	memset(list->list, '\0', sizeof(IntList)*INTLIST_SIZE);
	memset(&list, '\0', sizeof(IListArr));
}

void splitList(IntList * list, IntList * dest) {

	dest->size = list->size / 2;
	list->size -= dest->size;

	memcpy((void*) dest->list, (void*) (list->list + list->size), (size_t)(list->size * sizeof(int)));
}

int r_divide(IListArr* list) {
	int count = 1;
	IntList tmpA, tmpB;
	int i;

	for(i = list->size - 1; i >= 0; i--) {
		memcpy((void*) &tmpA, (void*) &list->list[i], sizeof(IntList));
		splitList(&tmpA, &tmpB);
		memcpy((void*) &list->list[i*2], (void*) &tmpB, sizeof(IntList));
		memcpy((void*) &list->list[(i*2)-1], (void*) &tmpA, sizeof(IntList));
	}
	list->size += list->size;
	if((list->list)[0].size > 1) {
		count += r_divide(list);
	}
	return count;
}

int mergeSort(IntList * list) {
	int count = 1;
	IListArr listArr = createIListArr();
	initIListArr(&listArr);

	printf("starting merge sort\n");
	memcpy((void*) &listArr.list[0], (void*) &list, sizeof(IntList));
	printf("list copied\n");
	listArr.size = 1;

	count += r_divide(&listArr);
	return count;
}

