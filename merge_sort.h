#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
	double x;
	struct _list* next;
} List;

int list_split(List** a, List** b, List* c);
int list_sort(List** x);
int list_merge(List** x, List* a, List* b);
void list_free(List* x);
void list_insert(List** lst, double a);

#endif
