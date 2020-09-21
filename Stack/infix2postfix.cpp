#include <iostream>
#include <climits>
#include <string>
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

	int size()
	{
		return top+1;
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

int prec(char op)
{
	if (op == '*')
		return 5;
	else if (op == '/')
		return 4;
	else if (op=='%')
		return 3;
	else if (op=='+')
		return 2;
	else if (op=='-')
		return 1;
	return 0;
}


int main()
{
	string s;

	cin>>s;
	string out = "";
	stack Stack(s.length());
	int maxprec=0;int o=0;
	for (int i=0;i<s.length();++i)
	{
		if (isdigit(s[i]))
			out+=s[i];
		else
		{
			if (s[i]=='(') Stack.push(s[i]);
			else if (s[i]==')')
			{
				--o;
				while(Stack.peek()!='(')
				{
					cout<<Stack.peek()<<" ";
					Stack.pop();
				}
				Stack.pop();
			}
			else if (s[i]=='(')
			{
				++o;
				Stack.push(s[i]);

			}
			else
			{
				if (Stack.isEmpty() || prec(s[i])>=maxprec || o>0)
				{
					Stack.push(s[i]);
					maxprec = prec(s[i]);
				}
				else
				{
					while((Stack.peek()!='(' || Stack.peek()==')' || (!Stack.isEmpty())))
					{
						if (prec(Stack.peek())<prec(s[i]))
						{
							break;
						}
						else
						{
							out+=Stack.peek();
							Stack.pop();
						}
					}
				}
			}
			
		}
	}

	while(Stack.isEmpty())
	{
		cout<<Stack.peek()<<"\n";
		Stack.pop();
	}

	return 0;
}