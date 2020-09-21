#include <iostream>
#include <climits>
using namespace std;

class stack
{
	int top;
	int size;
	int * arr;
public:
	stack(int size)
	{
		top = -1;
		this->size = size;
		arr = new int[size];
	}

	int isEmpty()
	{
		if (top==-1)
			return 1;
		else return 0;
	}

	int isFull()
	{
		if (top==this->size-1)
			return 1;
		else
			return 0;
	}

	bool push(int x)
	{
		if (!isFull())
		{
			arr[++top]=x;
			return true;
		}
		else
		{
			cout<<"Stack overflow\n";
			return false;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			return INT_MIN;
		}
		else
		{
			int temp;
			temp  = arr[top];
			--top;
			return temp;
		}
	}

	int size()
	{
		return top+1;
	}

	void display()
	{
		cout<<"current stack is : \n";
		for (int i=top;i>=0;--i)
		{
			cout<<arr[i]<<"\n";
		}
	}	

	int peek()
	{
		return arr[this->top];
	}
};

int main()
{
	int n;
	cout<<"Enter size of stack : ";
	cin>>n;
	stack Stack(n);
	Stack.push(1);
	Stack.push(3);
	Stack.display();
	while(!Stack.isEmpty()) 
	{
		Stack.pop();
	}
	Stack.display();
	Stack.push(1);
	Stack.push(3);
	Stack.push(1);
	Stack.push(3);
	Stack.push(1);
	Stack.push(3);
	Stack.display();
	cout<<"Top value "<<Stack.peek()<<endl;
	cout<<Stack.isFull()<<" full status\n";
	cout<<Stack.pop()<<" was popped\n";

	return 0;
}