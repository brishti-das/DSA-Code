#include<iostream>
using namespace std;
#define mx 100
int myQueue[mx];
int front = -1, rear = -1 ;

int isEmpty()
{
    return (front == -1) || (front > rear) ;
}
int isFull()
{
    return rear == mx-1 ;
}
void enqueue(int value)
{
    if (isFull())
    {
        cout <<"Queue overflow " << endl;
        return ;
    }
    if (isEmpty())
    {
       front = 0;
    }
    myQueue[++rear] = value ;
}
void dequeue()
{
    if(isEmpty())
    {
        cout << "Queue underflow" << endl;
        return ;
    }
    front++;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return ;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << myQueue[i] << endl;
    }
}
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(8);
    enqueue(10);
    dequeue();
    display();

    return 0;
}

