#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *elements;
    int logical_len;
    int alloc_len;
    int elem_size;
} stack;

void stack_new(stack *s, int elem_size) {
    assert(elem_size > 0);
    s->logical_len = 0;
    s->alloc_len = 4;
    s->elem_size = elem_size;
    s->elements = malloc(4 * elem_size);
    assert(s->elements != '\0');
}

void stack_dispose(stack *s) {
    free(s->elements);
}

static void stack_grow(stack *s) {
    s->alloc_len *= 2;
    s->elements = realloc(s->elements, s->alloc_len * s->elem_size);
    assert(s->elements != '\0');
}

void stack_push(stack *s, void *value) {
    if (s->logical_len == s->alloc_len) {
        stack_grow(s);
    }

    void *temp = (char *)s->elements + s->logical_len * s->elem_size;
    memcpy(temp, value, s->elem_size);

    printf("pushing %d -> %d\n", s->logical_len, *(int *)value);

    s->logical_len++;
}

void stack_pop(stack *s, void *elem_addr) {
    if (s->logical_len == 0) {
        printf("empty stack\n");
        return;
    }
    assert(s->logical_len > 0);
    s->logical_len--;
    void *source = (char *)s->elements + s->logical_len * s->elem_size;
    memcpy(elem_addr, source, s->elem_size);
}

void main(void) {
    int i;

    printf("stack program\n");

    stack s;

    //	printf("%d\n", s.logical_len);

    stack_new(&s, sizeof(int));

    for (i = 0; i < 10; i++) {
        stack_push(&s, &i);
    }

    int elem_addr;

    for (i = 0; i < s.alloc_len; i++) {
        stack_pop(&s, &elem_addr);
        printf("%d\n", elem_addr);
    }

    stack_dispose(&s);
}
