#include <stdarg.h>
#include <stdio.h>

void foo(int n, ...) {
    int i;
    void *addr = &n;

    va_list arguments;

    va_start(arguments, n);

    // printf("%p\n", addr);

    for (i = 0; i < n; i++) {
        int value;
        value = va_arg(arguments, int);
        printf("%d\n", value);
    }

    va_end(arguments);

    printf("%p->%d\n", addr, *(int *)addr);
    printf("%p->%d\n", (int *)addr + 1, *(int *)addr - 1);
}

int main(void) {
    int i = 10, j = 20;
    int n = 2;
    foo(n, i, j);
    return 0;
}
