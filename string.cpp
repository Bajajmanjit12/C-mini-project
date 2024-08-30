#include <iostream>
using namespace std;

int len = 0, len1 = 0;

class str_fun 
{
    char s1[100];
    char s2[100];

public:
    void accept();
    void display();
    void length();
    void copy();
    void reverse();
    void concatenate();
    void compare();
} s;

void str_fun::accept()
{
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
}
void str_fun::display()
{
    cout<<"\nFirst string:"<<s1;
    cout<<"\nSecond string:"<<s2;
}
void str_fun::length() 
{
    len = 0;
    len1 = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        len++;
    }
    cout<<"\nLength of First string is: " <<len;
    for (int i = 0; s2[i] != '\0'; i++) {
        len1++;
    }
    cout<<"\nLength of Second string is: " <<len1;
}

void str_fun::copy() 
{
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[i]='\0';
    cout<<"\nCopied string in first string: " <<s1;
}

void str_fun::reverse() 
{
    char temp;
    int i=0;
    for (int j = len - 1; j > i; j--) 
    {
        temp = s1[i];
        s1[i] = s1[j];
        s1[j] = temp;
        i++;
    }
    cout<<"\nReversed first string: " <<s1;
     i = 0;
    for (int j = len1 - 1; j > i; j--) 
    {
        temp = s2[i];
        s2[i] = s2[j];
        s2[j] = temp;
        i++;
    }
    cout<<"\nReversed Second string: " <<s2;
}

void str_fun::concatenate() 
{
    int i = len;
    for (int j = 0; s2[j] != '\0'; j++) {
        s1[i] = s2[j];
        i++;
    }
    cout << "\nConcatenated string: " << s1;
}

void str_fun::compare()
 {
    int flag = 0;

    if (len != len1) {
        flag = 1;
    } 
    else 
    {
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0) {
        cout<< "\nStrings are equal.";
    } else {
        cout<< "\nStrings are not equal.";
    }
}

int main() 
{
    int choice;
    do {
        cout<< "\n1.Accept\n2.Dispaly\n3.Length\n4.Copy\n5.Reverse\n6.Concatenate\n7.Compare\n0.Exit\n";
        cout<< "Enter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            case 1:s.accept();break;
            case 2:s.display();break;                
            case 3:s.length(); break;
            case 4: s.copy();break;
            case 5: s.reverse();break;
            case 6:s.concatenate(); break;
            case 7:s.compare(); break;
            default:cout << "\nInvalid choice\n";
                break;
        }
    } while (choice != 0);
    return 0;
}
