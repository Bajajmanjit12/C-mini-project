#include<iostream>
using namespace std;
int n;  //maximum size of queue
class deq
{
    int front,rear,ele;
    public:

    void insertFront();
    void insertRear();
    void deleteFront();
    void deleteRear();
    void display();
}d[100];

void deq :: insertRear()        //inserting an element from rear end
{
    if(rear == n-1)
    {
        cout << "\nQueue is full!";
    }
    else if(front == -1 && rear ==-1)
    {
        front=0;
        rear=0;
        cout<<"\n Enter the element to Insert :";
        cin>>d[rear].ele;
        rear ++;
    }
    else{
        cout<<"\n Enter the element to Insert :";
        cin>>d[rear].ele;
        rear ++;
    }
}

void deq :: insertFront()
{
    if(front ==0 && rear == n-1)
    {
        cout << "\nQueue is full!";
    }
    else if(front == -1 && rear ==-1)
    {
        front = n-1;
        rear=0;
        cout<<"\n Enter the element to Insert :";
        cin >> d[front].ele;
       
    }
    else
    {
        front --;
        cout<<"\n Enter the element to Insert :";
        cin >> d[front].ele;
        
    }
}

void deq :: deleteFront()
{
    if(rear ==-1 && front ==-1)
    {
        cout<<"\nQueue is empty!\n";
    }
    else if ((rear==front || front ==n-1))
    {
        cout<<"\nElement Deleted is :"<<d[front].ele;
        front=-1;
        rear=-1;
    }
    else{
        cout<<"\nElement Deleted is :"<<d[front].ele;
        front++;
    }
}

void deq ::deleteRear()
{
    if(rear ==-1 && front ==-1)
    {
        cout<<"\nQueue is empty!\n";
    }
    else if (rear==front)
    {
        cout<<"\nElement Deleted is :"<<d[rear].ele;
        front=-1;
        rear=-1;
    }
    else{
        cout<<"\nElement Deleted is :"<<d[rear].ele;
        rear--;
    }
}

void deq::display()
{
     if(front==-1 && rear==-1)
        {
            cout<<"\nQueue is empty!\n";
        }
        else
        {
        for(int i=front ; i <= rear ;i++)
        {
            cout<<d[i].ele<<"\t";
        }
        
        }
}
int main()
{
    int choice;

    cout<<"\nEnter size of queue:";
    cin>>n;

    do{
    cout<<"\n1.Insert element from rear end.\n2.Insert an element from front end.\n3.Delete element from front end.\n4.Delete an element from rear end.\n5.Display the elements\n";
    cout<<"\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1: 
        d[0].insertRear();
        break;

        case 2:
        d[0].insertFront();
        break;

        case 3: 
        d[0].deleteFront();
        break;

        case 4:
        d[0].deleteRear();
        break;

        case 5:
        d[0].display();
        break;


    }

    }while(choice != 0);
}