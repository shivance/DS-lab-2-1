#include <iostream>
using namespace std;

void printArray(int arr[],int size);
void merge(int arr[],int l,int mid,int r);
void mergesort(int arr[],int l,int r);

int main()
{
	int n;cout<<"Input the size : ";cin>>n;
	cout<<"Enter the elements :";int arr[n];
	for (int i=0;i<n;++i){
		cin>>arr[i];
	}

	printArray(arr,n);
	mergesort(arr,0,n-1);
	cout<<"SORTED array is :";
	printArray(arr,n);

	return 0;
}

void printArray(int arr[],int size)
{
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


void merge(int arr[],int l,int mid,int r)
{
	int n1 = mid-l+1;
	int n2 = r-mid;
	int L[n1],R[n2];
	int i=0,j=0,k;

	for (i=0;i<n1;i++) L[i] = arr[l+i];
	for (j=0;j<n2;j++) R[j] = arr[mid+1+j];

	//Now array has been divided into two temporary arrays
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else {
			arr[k]=R[j];
			j++;
		}

		k++;
	}

	while(i<n1){
		arr[k]=L[i];
		k++;
		i++;
	}

	while(j<n2){
		arr[k]=R[j];
		k++;
		j++;
	}

	//Only one array will have excess elements ;that's why only one of above loops will run
}

void mergesort(int arr[],int l,int r)
{
	if (l<r)
	{
		int mid = l+(r-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
	else return;
}
