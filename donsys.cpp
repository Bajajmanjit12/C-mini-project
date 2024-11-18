/*a charity management system need to manage the info about donors , donation and other relevant data. System need to maintain about each donor, system should able to add new donor, remove the donor, update the info of donor, search the specific donor. Also, it should display the info of all donor present in the datbase. Use the concept of linked list to implement above system.*/

#include<iostream>
using namespace std;

class donor
{
int id,amt;
string name,add;
donor *next;

public:

void accept();
void display();
void search();
void count();
void remove();
void update();

};

donor *start = NULL;
donor *temp;
void donor :: accept()
{

donor *newnode = new donor;
cout<<"\nEnter the details of donor:\n";
cout<<"\nID\tName\tAddress\tAmount\n";
cin>>newnode->id>>newnode->name>>newnode->add>>newnode->amt;
if(start == NULL)
{
start = newnode;

}
else
{
temp = start;
while(temp->next != NULL)
{
temp=temp->next;
}
temp->next = newnode;
}
newnode->next=NULL;
}

void donor :: display()
{

if(start == NULL)
{
cout<<"\nNo records are avialable!";
}
else
{
temp=start;
cout<<"\nID\tName\tAddress\tAmount\n";
while(temp != NULL)
{
cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->amt<<endl;
temp=temp->next;
}
}
}

void donor :: count()
{
int count=0--






0000000000000000000000000000000000000000000000000000;
if(start == NULL)
{
cout<<"\nNo records are avialable!";
}
else
{
temp=start;
while(temp != NULL)
{
temp=temp->next;
count++;
}
cout<<"\nNumber of records availablle:"<<count<<endl;
}

}

void donor :: search()
{
int i,flag=0;
if(start == NULL)
{
cout<<"\nNo record are available";
}
else
{
cout<<"\nEnter the id of donor to be search : ";
cin>>i;
temp = start;
while(temp!= NULL)
{
if(temp->id == i)
{
flag=1;
cout<<"\nRecord found\n";
cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->amt<<endl;
break;
}
temp=temp->next;
}
}

if(flag == 0)
{
cout<<"\nRecord not found";
}
}


void donor :: remove()
{

donor *q,*p;
int i,flag =0;

if(start == NULL)
{
cout<<"\nRecords are not available";
}
else
{
cout<<"\nEnter the id of donor to be delete: ";
cin>>i;

if(i == 1)
{
    temp=start;
    start = start -> next;
    cout <<"\n First record deleted\n";
    delete temp;
}
temp = start;
while(temp!= NULL)
{
if(temp->id == i)
{
flag=1;
p = temp;
break;
}
q=temp;
temp = temp->next;
}
}
if(flag == 1)
{
cout<<p<<endl;
cout<<"\nRecord deleted";
q->next=p->next;
delete p;

}
else
{
cout<<"\nRecord not found";
}

}

void donor :: update()
{
int i,flag=0;
if(start == NULL)
{
cout<<"\nNo record are available";
}
else
{
cout<<"\nEnter the id of donor to be update : ";
cin>>i;
temp = start;
while(temp!= NULL)
{
if(temp->id == i)
{
flag=1;
cout<<"\nRecord found\n";
cout<<"\nEnter new record";
cout<<"\nID\tName\tAddress\tAmount\n";
cin>>temp->id>>temp->name>>temp->add>>temp->amt;
break;
}
temp=temp->next;
}
}

if(flag == 0)
{
cout<<"\nRecord not found";
}

}



int main()
{
donor d;
int choice;

do{
cout<<"\n1.Accept\n2.Display\n3.count\n4.search\n5.Delete\n6.Update\n";
cout<<"\nEnter your choice:";
cin>>choice;

switch(choice)
{

case 1:
d.accept();
break;

case 2:
d.display();
break;

case 3:
d.count();
break;

case 4:
d.search();
break;

case 5:
d.remove();
break;

case 6:
d.update();
break;

}
}while(choice !=0);

}
