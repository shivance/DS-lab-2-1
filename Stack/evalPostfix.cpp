#include <iostream>
#include <climits>
using namespace std;

class stack
{
	int top;
	int size;
	char * arr;
public:
	stack(int size)
	{
		top = -1;
		this->size = size;
		arr = new char[size];
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

	bool push(char x)
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
			char temp;
			temp  = arr[top];
			--top;
			return temp;
		}
	}

	int sizef()
	{
		return size;
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

int eval(int a,int b,char* op)
{
	if (*op=='+')
		return a+b;
	else if (*op=='-')
		return a-b;
	else if (*op=='*')
		return a*b;
	else if (*op=='/')
		return a/b;
	else if (*op=='%')
		return a%b;
}

int post(string s)
{
	stack Stack(s.length());
	int tmp,v1,v2;
	for (int i=0;i<s.length();++i)
	{
		if (isdigit(s[i]))
		{
			Stack.push(s[i]);
		}
		else
		{
			v1 = Stack.peek() - '0';
			Stack.pop();
			v2 = Stack.peek() - '0';
			Stack.pop();
			tmp = eval(v2,v1,&s[i]) + '0';
			Stack.push(tmp);
			cout<<v1<<s[i]<<v2<<" = "<<(tmp-'0')<<"\n";
		}
	}

	int ans = Stack.peek()-'0';
	return ans;
}

int main()
{
	cout<<"Enter postfix string : ";
	string s;

	cin>>s;

	int ans = post(s);

	cout<<ans<<"\n";

	return 0;
}