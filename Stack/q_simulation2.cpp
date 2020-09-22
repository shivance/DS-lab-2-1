// push O(n) pop is O(1)

#include <iostream>
#include <climits>
using namespace std;

class stack
{
	int top;
	int size;
	int * arr;
public:
	stack(int s)
	{
		top = -1;
		size = s;
		arr = new int[s];
	}

	int isEmpty()
	{
		if (top==-1)
			return 1;
		else return 0;
	}

	bool isFull()
	{
		if (top==size-1)
			return true;
		else
			return false;
	}

	bool push(int x)
	{
		if (isFull())
		{
			//cout<<"Stack overflow\n";
			return false;
		}
		else 
		{
			arr[++top]=x;
			return true;
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

	int siz()
	{
		return top+1;
	}

	void display()
	{
		cout<<"contents of current queue is : \n";
		for (int i=top;i>=0;--i)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}	

	void displayrev()
	{
		cout<<"contents of current queue is : \n";
		for (int i=0;i<=top;++i)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}	
	int peek()
	{
		return arr[this->top];
	}
};

void push2queue(stack &am,stack &tmp,int val)
{
    while(!am.isEmpty())
    {
    	tmp.push(am.pop());
    }
    bool a = am.push(val);
    //bool a = am.push(val);
    if (a==false)
    {
    	cout<<"Queue overflow\n";
    	
    }
    while(!tmp.isEmpty())
    {
    	am.push(tmp.pop());
    }
    return ;
}

int pop4queue(stack&am,stack&tmp)
{
    int k = am.pop();
    return k;
}

int main()
{
	int n;
	cout<<"Enter max size of queue buffer : ";
	cin>>n;
	stack queue(n);
	stack tmpq(n);
    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the queue : "<<"\n";
    cout<<"To push integer <val> into queue :\n$ push <val>\n ";
    cout<<"To pop value from the queue\n$ pop\n";
    cout<<"To display the content of queue \n$ view\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    while(true)
    {
    	cin>>op;
    	if (op=="push")
    	{
    		cin>>val;
    		push2queue(queue,tmpq,val);
    		
    	}
    	else if (op=="pop")
    	{
    		k = pop4queue(queue,tmpq);
    		
    		if (k==INT_MIN)
    		{
    			cout<<"Queue underflow\n";
    			break;
    		}
    		else
    			cout<<"\n"<<k<<" popped from queue\n";
    	}
    	else if (op=="view")
    	{
    		queue.display();
    	}
    	else if (op=="exit")
    	{
    		break;
    	}
    }

	return 0;
}