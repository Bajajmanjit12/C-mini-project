/*Aim:To search for a target value in a sorted array using linear search and return its index if found*/
#include<iostream>
using namespace std;

void sortarray()           //to sort the array
{
	int arr[20],n,i,j;
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

int main()        //main function
{
	int arr[10],n,i,target,flag=0,count=0;
	cout << "Enter the size of array: ";     //accept size from user
    cin>>n;
    cout<<"Enter the array elements: ";      // accept array elements frm user
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
    
    cout<<"Enter the target to search:";       
	cin>>target;
	
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
	
	return 0;
}
}
