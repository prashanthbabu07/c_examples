#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	void *elements;
	int logical_len;
	int alloc_len;
	int elem_size;
	void (*free_stack_f)(void *);
} stack;


void stack_new(stack *s, int elem_size, void(*free_stack_f)(void *)) 
{
	assert(elem_size > 0);
	s->logical_len = 0;
	s->alloc_len = 4;
	s->elem_size = elem_size;
	s->elements = malloc(4 * elem_size);
	s->free_stack_f = free_stack_f;
	assert(s->elements != '\0');
}

void stack_dispose(stack *s)
{
	int i;
	if(s->free_stack_f != '\0') {
		for(i=0; i< s->logical_len; i++) {
			s->free_stack_f((char *)s->elements + i * s->elem_size);
		}
	}
	free(s->elements);
}

void free_string(void *addr)
{
	free(*(char **)addr);
}

static void stack_grow(stack *s)
{
	s->alloc_len *= 2;
	s->elements = realloc(s->elements, s->alloc_len * s->elem_size);
	assert(s->elements != '\0');
}

void stack_push(stack *s, void *value)
{
	if(s->logical_len == s->alloc_len) {
		stack_grow(s);
	}

	void *temp = (char *)s->elements + s->logical_len * s->elem_size;
	memcpy(temp, value, s->elem_size);
	s->logical_len++;
}

void stack_pop(stack *s, void *elem_addr)
{
	if(s->logical_len==0) {
		printf("empty stack\n");
		return;
	}
	assert(s->logical_len > 0);
	s->logical_len--;
	void *source = (char *)s->elements + s->logical_len * s->elem_size;
	memcpy(elem_addr, source, s->elem_size);
}

void main(void)
{

	int i;
	printf("stack program\n");
	stack s;
	const char *names[] = {"rekha", "ramya", "nithya", "pramila"};
	
	stack_new(&s, sizeof(char *), free_string);
	
	for(i=0; i<4; i++) {
		char *copy = strdup(names[i]);
		stack_push(&s, &copy);
	}
	
	char *name;	
	
	for(i=0; i<2; i++) {
		stack_pop(&s, &name);
		printf("%s\n", name);
	}
	
	stack_dispose(&s);
}
