#include <stdio.h>

typedef struct {
	int *elements;
	int logical_len;
	int alloc_len;
} stack;

void stack_new(stack *s);
void stack_dispose(stack *s);
void stack_push(stack *s, int elem);
void stack_pop(stack *s);

void stack_new(stack *s) 
{
	s->locial_len = 0;
	s->alloc_len = 4;
	s->elements = malloc(4 * sizeof(int));
	assert(s->elements != '\0');
}
