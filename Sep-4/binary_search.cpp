#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

void swap(int* a ,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int arr[],int size)
{
	for (int i=0;i<size;++i)
	{
		cout<<arr[i]<<" ";
	}
}

void shuffle_array(int arr[], int n) 
{ 
  

    unsigned seed = 0; 
    shuffle(arr, arr + n, 
            default_random_engine(seed)); 


} 


int binarySUtil(int arr[],int l,int r,int x)
{
	if (l>r)
	{
		return -1;
	}

	int mid = l + (r-l)/2;

	if (arr[mid]==x)
	{
		return mid;
	}

	else if (arr[mid]>x)
	{
		return binarySUtil(arr,l,mid,x);
	}
	else
	{
		return binarySUtil(arr,mid+1,r,x);
	}

}

int binaryS(int arr[],int size,int key)
{
	return binarySUtil(arr,0,size-1,key);
}


int linearS(int arr[],int size,int key)
{
	for (int i=0;i<size;++i)
	{
		if (arr[i]==key)
		{
			return i;
		}
	}

	return -1;
}

void insertSort(int arr[],int size)
{
	int i,j,curr ;

	for (i=1;i<size;++i)
	{
		curr = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>curr)
		{
			arr[j+1] = arr[j];
			--j;
		}

		arr[j+1]=curr;
	}
}

void bubbleSort(int arr[],int size)
{
	int count;

	while(count>0)
	{
		count=0;
		for (int i=0;i<size-1;++i)
		{
			if (arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				++count;
			}
		}
	}

	return;
}

void selectionSort(int arr[],int size)
{
	int mindex,curr,j ;

	for (int i=0;i<size-1;++i)
	{
		
		mindex = i;

		for (int j=i+1;j<size;++j)
		{
			if (arr[mindex]>arr[j])
				mindex = j;
		}

		swap(&arr[i],&arr[mindex]);
	}
}

int main()
{
	int n,inp,inp1;cout<<"Enter size : ";
	cin>>n;cout<<"\nEnter array elements : ";int arr[n];
		
	for (int i=0;i<n;++i) cin>>arr[i];
	n = sizeof(arr)/sizeof(arr[0]);

	while(true)
	{
		
		
		cout<<"Press 1 for sorting & press 2 for searching : ";
		cin>>inp;
		
		if (inp==1)
		{
			cout<<"Press 1 for Insertion Sort , 2 for Selection , 3 for Bubble \n";
			cin>>inp1;
			if (inp1==1)
			{
				insertSort(arr,n);
				printArr(arr,n);
				cout<<endl;
			}
			else if (inp1 ==2)
			{
				selectionSort(arr,n);
				printArr(arr,n);
				cout<<endl;
			}
			else if (inp1==3)
			{
				bubbleSort(arr,n);
				printArr(arr,n);
				cout<<endl;
			}

		}

		else if (inp==2)
		{
			int x;
			cout<<"Press 1 for linear search 2 for binary search\n";
			cin>>inp1;
			cout<<"Enter value to be searched : ";
			cin>>x;
			if (inp1==1)
			{
				bubbleSort(arr,n);
				int ans = linearS(arr,n,x);
				if (ans>=0)
				{
					cout<<x<<" is at index "<<ans<<'\n';
				}
				else cout<<"Not found\n";
			}
			else if (inp1 ==2)
			{
				bubbleSort(arr,n);
				int ans = binaryS(arr,n,x);
				if (ans>=0)
				{
					cout<<x<<" is at index "<<ans<<'\n';
				}
				else cout<<"Not found\n";	
			}
		}
		else break;

		cout<<"Press 0 to continue : ";
		int df ;cin>>df;
		if (df != 0) break;
	}	
	return 0;
}