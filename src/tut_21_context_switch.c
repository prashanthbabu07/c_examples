#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#define MEMORY 64000

ucontext_t p_fun1, p_fun2, p_main;
ucontext_t p_current;

void fun1()
{
	printf("fun1() running\n");
	setcontext(&p_main); //this calls main();
}

void fun2()
{
	printf("fun2() running\n");
	setcontext(&p_fun1);//this calls fun1();
}

void start(ucontext_t *p, void (*fun)(void))
{
	getcontext(p);
	p->uc_link = 0;
	p->uc_stack.ss_sp = malloc(MEMORY);
	p->uc_stack.ss_size = MEMORY;
	p->uc_stack.ss_flags = 0;
	makecontext(p, fun, 0);
}
int main(int argc, char *argv[])
{
	start(&p_fun1, fun1);
	getcontext(&p_main);
	getcontext(&p_current);
	start(&p_current, fun1);
	swapcontext(&p_main, &p_current);//this calls fun1();
	start(&p_fun2, fun2);
	swapcontext(&p_main, &p_fun2);//this calls fun2();
	printf("main() running\n");
}
