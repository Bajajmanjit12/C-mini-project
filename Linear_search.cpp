/*Aim:To search for a target value in a sorted array using linear search and return its index if found*/
#include<iostream>
using namespace std;
int n;

class L_search{
    int arr[30],target;
    public:
    void accept();
    void sortarray();
    void count_occ();
    void search();
}l;

void L_search::accept()
{
    cout << "Enter the size of array: ";     
    cin>>n;
    cout<<"Enter the array elements: ";      
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
	sortarray();

	cout << "The sorted array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void L_search::sortarray()  
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

void L_search::search()
{
    cout<<"Enter the target to search:";       
	cin>>target;
	int i,flag=0;
	for(i=0 ;i<n;i++)
	{
		if(arr[i]==target)
		{
			flag=1;
			cout<<"Target found at postion :"<<i<<endl;
			break;
		}
	}
	
	if(flag==0)
	{
		cout<<"Target not found!"<<endl;
	}
}

void L_search::count_occ()
{
    int i,count=0;
    for(i=0 ;i<n;i++)
	{
		if(arr[i]==target)
		{
		count++;
		}
	}
	cout<<"Number of occurrence of Target :"<<count<<endl;   //count the occurrences of target 
	for(i=0 ;i<n;i++)
	{
		if(arr[i]==target)
		{
		cout<<"Number of first occurrence of Target :"<<i<<endl; //display the position of first occurrence
		break;
		}
	}
	
	for(i=n-1 ;i>0;i--)
	{
		if(arr[i]==target)
		{
		cout<<"Number of last occurrence of Target :"<<i<<endl;    //display the position of last occurrence
		break;
		}
}
}
int main()      
{
    l.accept();
    l.search();
    l.count_occ();
	return 0;
}

