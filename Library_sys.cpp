#include<iostream>
#include <string>
using namespace std;
int n;
class Book
{
    int cost;
    string Author,Title;
    public:
    void accept();
    void display();
    void Asc();
    void Des();
    void count();
    void cost_less_than_500();
    void cost_more_than_500();
    void del_duplicate_with_temp();
    void del_duplicate_without_temp();
}B[100],c[100];

void Book :: accept()
{
    cout<<"Enter the Title of the Book:";
    cin>>Title;
    cout<<"Enter the Name of the Author:";
    cin>>Author;
    cout<<"Enter the cost of the book:";
    cin>>cost;
    cout<<endl;
}

void Book :: Asc()
{
    Book T;
    for(int i=0; i<n ; i++)
    {
        for(int j=i; j<n;j++)
        {
            if(B[i].cost > B[j].cost)
            {
                T = B[i];
                B[i]=B[j];
                B[j]=T;
            }
        }
        B[i].display();
    }
}

void Book :: Des()
{
    Book T;
    for(int i=0; i<n ; i++)
    {
        for(int j=i; j<n;j++)
        {
            if(B[i].cost < B[j].cost)
            {
                T = B[i];
                B[i]=B[j];
                B[j]=T;
            }
        }
         B[i].display();
    }
}

void Book :: count()
{
    int count=0;
    for(int i=0 ;i<n;i++)
    {
        count++;
    }
    cout<<"\nTotal Number of Records:"<<count<<"\n";
    cout<<endl;
}

void Book :: cost_less_than_500()
{
    for(int i=0;i<n;i++)
    {
    if(B[i].cost <= 500)
    {
        B[i].display();
    }
    }

}

void Book :: cost_more_than_500()
{
    for(int i=0;i<n;i++)
    {
    if(B[i].cost > 500)
    {
        B[i].display();
    }
    }

}

void Book :: del_duplicate_with_temp()
{
    int i,j=0;
    c[0]=B[0];
    for( i=1 ;i<n ;i++)
    {
    
            if( B[i].Title != c[j].Title && B[i].Author != c[j].Author )
            {
                j++;
                c[j] = B[i];
            }
        
    }
   
    for( i=0 ; i<=j ;i++)
    {
        c[i].display();
    }
       
}

void Book :: del_duplicate_without_temp()
{
    int i,j=0;
    for( i=0 ;i<n ;i++)
    {
        if( B[i].Title != B[j].Title && B[i].Author != B[j].Author )
        {
            j++;
            B[j] = B[i];
        }
    }
   

    for( i=0 ; i<=j ;i++)
    {
        B[i].display();
    }
}
void Book :: display()
{
   
        cout<<Title<<"\t"<<Author<<"\t\t"<<cost<<"\n";
}

int main()
{
    int choice,i;
    do{
        cout<<"\n1.Accept\n2.Display\n3.Ascending\n4.Descending\n5.Count the Records\n6.Display record for Books Having cost less than or equal to 500\n7.Display record for Books Having cost more than 500\n8.Delete duplicates by using Temporary Array\n9.Delete duplicates without using Temporary Array\n0.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1: cout<<"Enter the Number of Records you want to store:";
                    cin>>n;
                    for(int i=0; i<n ;i++)
                    {
                        B[i].accept();
                    }
                    break;
            case 2:  cout<<"LIBRARY RECORD"<<endl; 
                    cout<<"Title"<<"\t"<<"Author Name"<<"\t"<<"Cost"<<"\n";
                    for(int i=0 ;i<n ;i++)
                    {
                        B[i].display();
                    }
                    break;
            case 3: B[i].Asc();break;
            case 4: B[i].Des();break;
            case 5: B[i].count();break;
            case 6: B[i].cost_less_than_500();break;
            case 7: B[i].cost_more_than_500();break;
            case 8: B[i].del_duplicate_with_temp();break;
            case 9: B[i].del_duplicate_without_temp();break;
            default: cout<<"Invalid choice";break;
        }
    }while(choice !=0);

    return 0;
}