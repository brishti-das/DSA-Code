#include<iostream>
using namespace std;
#define mx 100
int myStack[mx];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == mx-1;
}

void push(int value)
{
    if(isFull())
    {
        cout<< "Stack overflow" <<endl;
        return ;
    }
    myStack[++top]=value;

}
void pop ()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    --top;
}
int peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return myStack[top];
}
void display()
{
    if(isEmpty())
    {
        cout<< "Stack is empty" <<endl;
        return;
    }
    for(int i=top; i>=0; i--)
    {
        cout<< myStack[i]<<endl;
    }
}
int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    pop();
    display();
    return 0;
}

