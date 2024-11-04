#include<iostream>
using namespace std;

class str_pal
{
    string str;
    public:
    void accept();
    void is_palindrome();
}s;

void str_pal :: accept()
{
    cout<<"\nEnter the string:";
    cin>>str;
}

void str_pal :: is_palindrome()
{
    int len,top=-1,i,flag=0;
    len=str.length();
    char stack[len];

    for(i=len-1; i>=0;i--)
    {
        stack[++top]= str[i];
    }

    for(i=0;i<len;i++)
    {
        if(str[i]==stack[i])
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        cout<<"\nString is palindrome.\n";
    }

    if(flag==0)
    {
            cout<<"\nString is not palindrome.\n";
    }
}

int main()
{
int choice;
do
{
cout<<"\n1.Accept\n2.check palindrome or not\n0.Exit";
cout<<"\nEnter your choice:";
cin>>choice;

switch(choice)
{
case 1:s.accept();
      break;
case 2:s.is_palindrome(); 
        break;
case 0: cout<<"\nExiting.....\n";
        break;
default:cout<<"\nInvalid choice\n"<<endl;
        break;
}

}while(choice!=0);
}