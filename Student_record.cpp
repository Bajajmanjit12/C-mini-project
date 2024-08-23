#include<iostream>
using namespace std;
int n;
class student
{
    int rno;
    string name,Add;
    public:
    void accept();
    void display();
    void L_search();
    void B_search();
    void feedback();
}s[100];

void student :: accept()
{
    
    cin>>rno>>name>>Add;

}

void student :: display()
{
    cout<<"\n"<<rno<<"\t"<<name<<"\t"<<Add;
}

void student :: L_search()
{
    int r,flag=0;
    cout<<"\nEnter the roll no of Student whom you want to search:";
    cin>>r;
    for(int i=0;i<n;i++)
    {
        if(r==s[i].rno)
        {
            flag=1;
            cout<<"\nStudent was present in the program\n";
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nStudent was not present in the program\n";
    }
}

void student ::B_search()
{
    student t;
    int mid,high=n-1;
    int low=0,r,flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(s[i].rno > s[j].rno)
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
        s[i].display();
    }
    cout<<"\nEnter the roll no of student you want to search:\n";
    cin>>r;
    while(low<=high)
    {
    mid=(high+low)/2;
    if(s[mid].rno ==r)
    {
        cout<<"\nStudent was present in the program.\n";
        flag=1;
        break;
    }
    else if(s[mid].rno > r)
    {
        high=mid-1;
    }
    else
    {
        low=mid+1;
    }
    }
    if(flag==0)
    {
        cout<<"\nStudent was not present in the program.\n";
    }
}

void student :: feedback()
{
    int sum=0;
    cout<<"Feedback from student\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Roll No:"<<s[i].rno<<endl;
        int ans[5];
        cout<<"\nDid you find the training materials useful?\n";
        cin>>ans[0];
        cout<<"Was the duration of training appopriate?\n";
        cin>>ans[1];
        cout<<"Did you have enough oppourtunities to interact with trainer?\n";
        cin>>ans[2];
        cout<<"Was the trainer knowledgeble about the subjects?\n";
        cin>>ans[3];
        cout<<"Did the training improve your skills or knowledge?\n";
        cin>>ans[4];  
    
        for(int j=0;j<5;j++)
        {
            sum = sum + ans[j];
        }
    }
    int avg = (sum*100)/(5*n);
    cout<<"Average:"<<avg;

    if(avg>=80)
    {
        cout<<"\nTraining was good!\n";
    }
    else{
        cout<<"\nTraining was not good!";
    }

    
}
int main()
{
    int choice,i;
    cout<<"\nEnter the Total number of Students:";
    cin>>n;

    do{
    cout<<"\n1.Accept\n2.Display\n3.Linear search\n4.binary search\n5.Feedback\n0.Exit\n";
    cout<<"Enter your choice:";
    cin>>choice;

    switch (choice)
    {
    case 1:cout<<"Enter the rollno,name and address\n";
    cout<<"\n"<<"rno"<<"\t"<<"name"<<"\t"<<"Add\n";
    for( i=0;i<n;i++)
            {
                s[i].accept();
            }
            break;
    case 2: cout<<"\n"<<"rno"<<"\t"<<"name"<<"\t"<<"Add";
            for( i=0 ;i<n;i++)
            {
                s[i].display();
            }
            break;
    case 3: s[i].L_search();
            break;
    case 4: s[i].B_search();
            break;
    case 5: s[i].feedback();break;
    default:cout<<"\nExiting...";
        break;
    }
    }while(choice != 0);
}
