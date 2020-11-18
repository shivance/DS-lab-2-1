#include <iostream>
using namespace std; 

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int l, int r) 
{ 
	int pivot = arr[r]; // pivot 
	int i = (l - 1); // Index of smaller element 

	for (int j = l; j <= r - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[r]); 
	return (i + 1); 
} 

//driver code
void quickSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int pi = partition(arr, l, r); 
		quickSort(arr, l, pi - 1); 
		quickSort(arr, pi + 1, r); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() 
{ 
	int n;cout<<"Enter size of array : ";cin>>n;
	int arr[n];
	cout<<"Enter the array elements : \n";
	for (int i=0;i<n;++i) cin>>arr[i];
	quickSort(arr, 0, n - 1); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 


