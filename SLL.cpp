#include<iostream>
using namespace std;

class Lib
{
    //data field
    string tt,aut,pub;
    int price,id;
    //pointing of next addressog lib
    Lib *next;
    Lib *temp;

    public:
    void accept();
    void display();
    void search();
    void update();
    void displaycnt();
    void deletenode();

}*start = NULL,t; //dynamic object

void Lib :: accept()
{
   
    Lib *newnode;
    newnode = new Lib;
    cout<<"\nEnter details [id,title,author,publisher,price] :";
    cin >> newnode->id >> newnode->tt>>newnode ->aut>>newnode->pub >>newnode->price ;
    newnode->next=NULL;

    if(start == NULL)
    {
        start = newnode;
        
    }
    else{

        temp = start;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void Lib ::display()
{
    
    temp=start;
    cout<<"Id"<<"\t"<<"Title"<<"\t"<<"Author"<<"\t"<<"Pub"<<"\t"<<"price"<<"\n";
    while(temp!=NULL)
    {
        cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"<<temp->price;
        temp=temp->next;
    }
}


void Lib :: search()
{
    int i,flag=0;
    cout<<"\nEnter the Id of book to be search:";
    cin>>i;

    temp=start;
    while(temp !=NULL)
    {
        if(temp->id == i)
        {
            flag=1;
            cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"<<temp->price;
            break;
        }
        temp=temp->next;
    }

    if(flag==1)
    {
        cout<<"\nBook is found!\n";
    }

    if(flag ==0)
    {
        cout<<"\n Book Not found!\n";
    }
}


void Lib::update()
{
    int i,flag=0;
    cout<<"\nEnter the Id of book to be update:";
    cin>>i;

    temp=start;
    while(temp !=NULL)
    {
        if(temp->id == i)
        {
            flag=1;
            cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"<<temp->price;
            cout<<"\nEnter new details:\n";
            cin>>temp->id>>temp->tt>>temp->aut>>temp->pub>>temp->price;
            break;
        }
        temp=temp->next;
    }

     if(flag ==0)
    {
        cout<<"\n Book Not found!\n";
    }

}


void Lib ::displaycnt()
{
    int count=0;
    temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    cout<<"\nTotal Number of nodes are:"<<count<<endl;
}

void Lib::deletenode()
{
int i,flag=0;
    Lib *p;
    if(start ==NULL)
        {
            cout<<"\nNo records are available\n";
        }

    else{
    
    cout<<"\nEnter the Id of book to be delete:";
    cin>>i;

    
    while(temp->next !=NULL)
    {
        
        if(temp->id == i)
        {
            flag=1;
            cout<<"\n"<<temp->id<<"\t"<<temp->tt<<"\t"<<temp->aut<<"\t"<<temp->pub<<"\t"<<temp->price;
            cout<<"\nRecord is deleted!!!\n";
            p=temp;
            break;
        }
        
        temp=temp->next;
        }

    
        p->next=temp->next;
        delete temp;
        
    }


    if(flag ==0)
    {
        cout<<"\n Book Not found!\n";
    }
    
}
int main()
{
    int choice;
do{
    cout<<"\n1.Accept\n2.display\n3.search\n4.Modify\n5.Display the count\n6.Delete the record\n";
    cout<<"\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        t.accept();
        break;

        case 2:
        t.display();
        break;

        case 3:
        t.search();
        break;

        case 4:
        t.update();
        break;

        case 5:
        t.displaycnt();
        break;

        case 6:
        t.deletenode();
        break;
    }

}while(choice!=0);
}
