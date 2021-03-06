#ifndef INTLIST_H
#define INTLIST_H

#define INTLIST_SIZE 9999
#define INTLIST_RANGE 200

typedef struct intList {
	int list[INTLIST_SIZE];
	int size;
} IntList;

IntList createIntList();

void initialiseIntList(IntList *);

int insertIntList(IntList*, int);

int removeIntList(IntList*, int);

void displayIntList(IntList*);

int fillIntList(IntList*);

void copyIntList(IntList*, IntList*);

#endif
