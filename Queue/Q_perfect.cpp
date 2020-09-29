#include <iostream>
#include <climits>

using namespace std;

class Queue
{

	int size,front,rear;
	unsigned capacity;
	int* arr;
public:
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

	void display()
	{
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

int main()
{
	unsigned n;
	cout<<"Enter max size of queue buffer : ";
	cin>>n;
	Queue q(n);
	
    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the queue : "<<"\n";
    cout<<"To push integer <val> into queue :\n$ enqueue <val>\n ";
    cout<<"To pop value from the queue\n$ dequqe\n";
    cout<<"To display the content of queue \n$ view\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    bool flg;
    while(true)
    {
    	cin>>op;
    	if (op=="enqueue")
    	{
    		cin>>val;
    		flg = q.enq(val);
    		if (flg == false)
    		{
    			cout<<"Overflow\n";
    		}
    	}
    	else if (op=="dequeue")
    	{
    		int k = q.deq();
    		if (k==INT_MAX)
    		{
    			cout<<"Queue underflow :/\n";
    		}
    		else
    		{
    			cout<<k<<" dequeued from queue\n";
    		}
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