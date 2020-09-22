#include <iostream>
using namespace std; 

int top = -1;

bool isEmpty()
{
	if (top == -1) return 1;
	else return 0;
}

void push(int stack[],int n,int x)
{
	if (top == n-1) cout<<"Stack Overflow";
	else
	{
		top = top +1;
		stack[top]=x;
	}
}

void pop(int stack[],int n)
{
	if (top == -1) cout<<"Stack underflow";
	else {
		cout<<stack[top]<<" ";
		top = top -1;
	}
}

int size()
{
	return top + 1;
}

int main()
{
	int T,N;
	long long int A;
	cin>>T;
	for (int i=0;i<T;++i)
	{
		cin>>N;
		int stack[N];
		for (int j=0;j<N;++j)
		{
			cin>>A;
			push(stack,N,A);
		}

		for (int j=0;j<N;++j)
		{
			pop(stack,N);
		}
	}

	return 0;	
}