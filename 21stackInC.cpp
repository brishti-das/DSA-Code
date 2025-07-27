#include <stdio.h>
#define mx 100
int myStack[mx];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == mx - 1;
}

void push(int value)
{
    if (isFull()) {
        printf("Stack overflow.\n");
        return;
    }
    myStack[++top] = value;
}

void pop()
{
    if (isEmpty()) {
        printf("Stack underflow.\n");
        return;
    }
    top--;
}


int main()
{

    for (int i = 0; i < mx + 2; i++) {
        push(i);
    }

    for (int i = 0; i < mx + 3; i++) {
        pop();
    }

    return 0;
}

