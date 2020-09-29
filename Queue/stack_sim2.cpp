// push O(n) pop O(1)

#include <iostream>
#include <climits>

using namespace std;

class Queue
{
	int front,rear;
	unsigned capacity;
	int* arr;
public:
	int size;
	Queue(unsigned s)
	{
		size = 0;
		arr = new int[s];
		capacity = s;
		front = rear = -1;
	}

	bool isEmpty()
	{
		if (size==0)
			return true;
		else 
			return false;
	}

	bool isFull()
	{
		if (size == capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool enq(int val)
	{
		if (isFull())
		{
			return false;
		}
		else if (isEmpty())
		{
			front = 0;rear = 0;
			arr[rear] = val;
			++size;
			return true;
		}
		else 
		{
			rear=(rear+1)%capacity;
			++size;
			arr[rear]=val;
			return true;
		}
	}

	int deq()
	{
		if (isEmpty())
		{
			return INT_MAX;
		}

		else if (size == 1)
		{
			size--;
			int k = arr[front];
			front = rear = -1;
			return k;
		}

		else
		{
			size--;
			int k = arr[front];
			front = (front+1)%(capacity);

			return k;
		}
	}

	int fron()
	{
		return arr[front];
	}

	int rea()
	{
		return arr[rear];
	}

	/*void display()
	{
		//cout<<"front = "<<front<<" rear = "<<rear<<endl;
		if (front==-1 && rear==-1)
		{
			cout<<"queue is Empty\n";
		}

		else if (front <= rear)
		{
			//cout<<"front <= rear\n";
			
			for (int i=rear;i>=front;--i)
			{
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			for (int i=rear;i>=0;--i)
			{
				cout<<arr[i]<<" ";
			}
			for (int i=capacity-1;i>=front;--i)
			{
				cout<<arr[i]<<" ";
			}
			
			cout<<"\n";
		}
	}*/

	void display()
	{
		//cout<<"front = "<<front<<" rear = "<<rear<<endl;
		if (front==-1 && rear==-1)
		{
			cout<<"queue is Empty\n";
		}

		else if (front <= rear)
		{
			//cout<<"front <= rear\n";
			
			for (int i=front;i<=rear;++i)
			{
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		}
		else
		{
			for (int i=front;i<capacity;++i)
			{
				cout<<arr[i]<<" ";
			}
			for (int i=0;i<=rear;++i)
			{
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		}
	}

};

void push2stack(Queue &q,Queue &tmp,int val)
{
	tmp.enq(val);
	while(!q.isEmpty())
	{
		tmp.enq(q.deq());
	}
	while(!tmp.isEmpty())
	{
		q.enq(tmp.deq());
	}
}

int pop4stack(Queue &q, Queue &tmp)
{
	int k = q.deq();
	return k;
}

int main()
{
	unsigned n;
	cout<<"Enter max size of queue buffer : ";
	cin>>n;
	Queue q(n);
	Queue tmp(n);
	
    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the stack : "<<"\n";
    cout<<"To push integer <val> into stack :\n$ push <val>\n ";
    cout<<"To pop value from the stack\n$ pop\n";
    cout<<"To display the content of stack \n$ view\n";
    cout<<"To exit the operation\n$ exit\n";
    cout<<"\n\n";
    bool flg;
    while(true)
    {
    	cin>>op;
    	if (op=="push")
    	{
    		cin>>val;
    		flg = q.enq(val);
    		if (flg == false)
    		{
    			cout<<"Stack Overflow:/\n";
    		}
    	}
    	else if (op=="pop")
    	{
    		int a = pop4stack(q,tmp);
    		if (k>=(INT_MAX-1))
    			
    		{
    			cout<<"Underflow :/\n";
    			break;
    		}
    		else
    		cout<<a<<" popped from stack\n";
    	}
    	else if (op=="view")
    	{
    		q.display();
    	}
    	else if (op=="exit")
    	{
    		break;
    	}
    }

	return 0;
}