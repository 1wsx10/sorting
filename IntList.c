#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IntList.h"

IntList createIntList() {
	IntList list;
	/*
	list.size = 0;
	*/
	return list;
}

void initialiseIntList(IntList * intList) {
	memset(intList, 0, sizeof(IntList));
	/*
	intList->size = 0;
	*/
}

int fillIntList(IntList * intList) {
	int i;

	for(i = 0; i < INTLIST_SIZE; i++) {
		intList->list[i] = rand() % INTLIST_RANGE;
		intList->size++;
	}
	return EXIT_SUCCESS;
}

int insertIntList(IntList * intList, int value) {
	int i, insertPosition;

	/* bounds check */
	if(intList->size == INTLIST_SIZE)
		return EXIT_FAILURE;
	
	/* find position */
	for(i = 0; i < intList->size; i++) {
		if(value < intList->list[i]) {
			break;
			/* i++ in for does not apply if you do break */
		}
	}

	insertPosition = i;
	
	/* insert */
	intList->size++;
	for(i = intList->size - 1; i > insertPosition; i--) {
		intList->list[i] = intList->list[i-1];
	}

	intList->list[insertPosition] = value;
	return EXIT_SUCCESS;
}

int removeIntList(IntList *intList, int value) {
	int i;

	for(i = 0; i < intList->size; i++) {
		if(i == value) {
			break;
		}
	}

	if(i == intList->size) {
		return EXIT_FAILURE;
	}

	for(; i < intList->size - 1; i++) {
		intList->list[i] = intList->list[i+1];
	}

	intList->size--;
	return EXIT_SUCCESS;
}

void displayIntList(IntList * intList) {
	int i;

	for(i = 0; i < intList->size; i++) {
		printf("pos %d: %d\n", i, intList->list[i]);
	}
	printf("size = %d\n", intList->size);
}

void copyIntList(IntList *start, IntList *dest) {
	int i;

	for(i = 0; i < start->size; i++) {
		dest->list[i] = start->list[i];
	}
	dest->size = start->size;
}





















