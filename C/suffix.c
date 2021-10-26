#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top, stack[1000];

#define push(x) stack[top++] = x
#define pop() stack[--top]

int main()
{
  int a, b;
  char op, buf[100];
  while (scanf("%s", buf) != EOF) {
    if (strchr("+-*/", buf[0]) && !buf[1]) {
      op = buf[0];
      b = pop();
      a = pop();
      switch(op) {
        case '+': push(a + b); break;
        case '-': push(a - b); break;
        case '*': push(a * b); break;
        case '/': push(a / b); break;
      }
    } else
      push(atoi(buf));
  }
  printf("%d\n", pop());

  return 0;
}
