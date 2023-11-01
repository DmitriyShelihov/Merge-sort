#include "merge_sort.h"

int list_sort(List** x)
{
	List* a = *x;
	List* b = *x;
	List* c = *x;
	if (!*x || !(*x)->next)
        return 0;
	list_split(&b, &c, NULL);
	list_sort(&a);
	list_sort(&b);
	return list_merge(x, a, b);
}

int list_split(List** a, List** b, List* c)
{
    if (!*b || !(*b)->next)
    {
		c->next = NULL;
		return 0;
	}
	c = *a;
	*a = (*a)->next;
    *b = ((*b)->next)->next;
	return list_split(a,b,c);
}

int list_merge(List** x, List* a, List* b)
{
	if (a && b)
    {
		if (a->x < b->x)
        {
			*x = a;
			return list_merge(&(*x)->next, a->next, b);
		}
        else
        {
			*x = b;
			return list_merge(&(*x)->next, a, b->next);
		}
	}
    else if (a)
		*x = a;
	else
		*x = b;
	return 0;
}

void list_free(List* x)
{
	if (!x)
        return;
	List *n = x->next;
	free(x);
	list_free(n);
}

void list_insert(List** lst, double a)
{
	List* n = (List*)malloc(sizeof(List));
	*n = (List){a, *lst};
	*lst = n;
}

int main()
{
	double a;
	List* lst = NULL;
	while (scanf("%lf", &a) != EOF)
		list_insert(&lst, a);
	list_sort(&lst);
	List* x;
	for ( x = lst; x != NULL; x = x->next )
		printf("%lf\n", x->x);
	list_free(lst);
}
