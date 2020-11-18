#include <iostream>
using namespace std;

void insertionS(int arr[],int size)
{
	int min_index;int tmp;
	for (int i=0;i<size-1;i++){
		min_index = i;
		for (int j=i+1;j<size;j++){
			if (arr[j] < arr[min_index])
			{
				min_index=j;
			}
		}
		tmp = arr[i];
		arr[i]= arr[min_index];
		arr[min_index]=tmp;
	}
}

void print(int arr[],int size)
{
	for (int i=0;i<size;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	cout<<"Enter no of elements : ";cin>>n;
	int arr[n];
	cout<<"Enter the array : \n";
	for (int i=0;i<n;++i) cin>>arr[i];
	
	insertionS(arr,n);
	print(arr,n);
	
	return 0;

}