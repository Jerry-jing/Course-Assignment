#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct stack {
	char* a[MAXSIZE];
	int top;
}Stack;
void push(Stack* s, char* x) {//ÈëÕ»
	if (s->top == MAXSIZE) {
		printf("\nThe sequence stack is full!");
		exit(1);
	}
	else {
		s->a[s->top] = x;
		s->top++;
	}
}
char* pop(Stack* s) {//³öÕ»
	s->top--;
	return s->a[s->top];
}
int main() {
	Stack backst, forst;
	backst.top = 0;
	forst.top = 0;
	char command[100] = "VISIT";
	char url[100] = { "http://www.acm.org/", };
	push(&backst, url);
	while (gets_s(command),strcmp(command, "QUIT") != 0) {
		if(strcmp(command, "VISIT") == 0) {
			char *u = new char[100];
			gets_s(u, 100);
			push(&backst, u);
			puts(u);
			while (forst.top != 0) {
				pop(&forst);
			}
		}
		else if(strcmp(command, "BACK") == 0) {
			if (backst.top - 1 == 0) {
				printf("Ignored\n");
			}
			else {
				char* ur = pop(&backst);
				push(&forst, ur);
				puts(backst.a[backst.top - 1]);
			}					
		}
		else if (strcmp(command, "FORWARD") == 0) {
			if (forst.top == 0) {
				printf("Ignored\n");
			}
			else {
				char* ur = pop(&forst);
				push(&backst, ur);
				puts(forst.a[forst.top]);
			}
		}	
	}	
	return 0;
}
