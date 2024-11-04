#include<iostream>
using namespace std;
int n;
class Cqueue
{
    int front=-1,rear=-1;
    int q[100];
    public:

    void enqueue();
    void dequeue();
    void display()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"\nQueue is empty!\n";
        }
        else
        {
        int i=front;
        while( i != rear)
        {
            cout<<q[i]<<"\t";
            i=(i+1) % n;
        }
        cout<<q[rear];
        }
    }
}q;

void Cqueue :: enqueue()
{
    int ele;
    if((rear + 1) % n == front)
    {
        cout<<"\nQueue is Full!\n ";
    }
    else if(rear==-1 && front ==-1)
    {
        front=0;
        cout<<"\nEnter the element :";
        cin>>ele;
        rear = (rear+1) % n;
        q[rear]=ele;
    }
    else{
        cout<<"\nEnter the element :";
        cin>>ele;
        rear = (rear+1) % n;
        q[rear]=ele;
    }
}

void Cqueue ::dequeue()
{
    if(rear ==-1 && front ==-1)
    {
        cout<<"\nQueue is empty!\n";
    }
    else if (rear==front)
    {
        cout<<"\nElement Deleted is :"<<q[front];
        front=-1;
        rear=-1;
    }
    else{
        cout<<"\nElement Deleted is :"<<q[front];
        front = (front +1) % n;
    }
    
}

int main()
{
    int choice;
    cout<<"\nEnter the size of queue:";
    cin>>n;
    do{
    cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n0.exit";

    cout<<"\nEnter Your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1: q.enqueue();break;
        case 2: q.dequeue();break;
        case 3: q.display();break;

    }

    }while(choice != 0);

    return 0;
}

