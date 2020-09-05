#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
	int *elements;
	int logical_len;
	int alloc_len;
} stack;

void stack_new(stack *s);
void stack_dispose(stack *s);
void stack_push(stack *s, int elem);
int stack_pop(stack *s);

void stack_new(stack *s) 
{
	s->logical_len = 0;
	s->alloc_len = 4;
	s->elements = malloc(4 * sizeof(int));
	assert(s->elements != '\0');
}

void stack_dispose(stack *s)
{
	free(s->elements);
}

void stack_push(stack *s, int value)
{
	if(s->logical_len == s->alloc_len) {
		s->alloc_len *= 2;
		s->elements = realloc(s->elements, s->alloc_len * sizeof(int));
		assert(s->elements != '\0');
	}

	s->elements[s->logical_len] = value;
	s->logical_len++;
}

int stack_pop(stack *s)
{
	assert(s->logical_len > 0);
	s->logical_len--;
	return s->elements[s->logical_len];
}

void main(void)
{

	int i;
	
	printf("stack program\n");
	
	stack s;
	
//	printf("%d\n", s.logical_len);
	
	stack_new(&s);
	
	for(i=0; i<10; i++) {
		stack_push(&s, i);
	}
	
	for(i=0; i<s.alloc_len; i++) {
		printf("%d\n", stack_pop(&s));
	}
	
	stack_dispose(&s);
}
























