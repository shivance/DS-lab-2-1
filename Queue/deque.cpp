#include <iostream>
#include <climits>

using namespace std;

class deq
{
	int siz,f,r;
	unsigned capacity;
	int *arr;
public:
	deq(unsigned cap)
	{
		capacity = cap;
		arr = new int[cap];
		siz=0;
		f = -1;
		r = 0;
	}

	int size()
	{
		return siz;
	}

	int front()
	{
		if (siz==0)
		{
			return -1;
		}
		return arr[f];
	}

	int rear()
	{
		if (siz==0)
		{
			return -1;
		}
		return arr[r];
	}

	void push_back(int data)
	{
		if ((unsigned)siz==capacity)
		{
			cout<<"Overflow in push attempt\n";
			return;
		}

		if (f==-1)
		{
			f=0;
			r=0;
			arr[r] =data;	
		}
		else{
			r=(r+1)%capacity;
			arr[r] =data;
		}
		siz++;
	}

	void push_front(int data)
	{
		if (siz== capacity)
		{
			cout<<"Overflow in push attempt\n";
			return ;
		}

		if (f==-1)
		{
			f = 0;
			arr[f] = data;
		}
		else if (f==0){
			f = capacity-1;
			arr[f] = data;
		}
		else
		{
			f = (f-1)%capacity;
			arr[f] = data;
		}
		siz++;
	}

	int pop_back()
	{
		if (siz==0)
		{
			//cout<<"Underflow while pop attempt\n";
			return INT_MAX;
		}
		if (siz==1)
		{
			int k = arr[r];
			f = -1;
			siz--;
			return k;
		}
		int k = arr[r];
		if (r==0)
		{
			r = capacity-1;
		}
		else{
			r = (r-1)%capacity;
		}
		siz--;
		return k;
	}


	int pop_front()
	{
		if (siz==0)
		{
			//cout<<"Underflow while pop attempt\n";
			return INT_MAX;	
		}
		if (siz==1)
		{
			int k = arr[f];
			f = -1;
			siz--;
			return k;
		}

		int k = arr[f];
		if (f==0)
		{
			f = capacity-1;
		}
		else{
			f = (f+1)%capacity;
		}
		siz--;
		return k;
	}

	void display()
	{
		if (siz==0)
		{
			cout<<"Empty queue\n";
			return;
		}
		if (f<=r)
		{
			cout<<"this\n";
			for (int i=0;i<=r;++i)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"that\n";
			for (int i=f;i<capacity;++i)
				cout<<arr[i]<<" ";

			for (int i=0;i<=r;++i)
				cout<<arr[i]<<" ";

			cout<<endl;
		}
	}
};


int main()
{
	unsigned n;
	cout<<"Enter max size of queue buffer : ";
	cin>>n;
	deq q(n);
	
    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the queue : "<<"\n";
    cout<<"To push integer <val> into front of queue :\n$ push_front <val>\n ";
    cout<<"To push integer <val> into back of queue :\n$ push_back <val>\n ";
    cout<<"To pop value from front of the queue\n$ pop_front\n";
    cout<<"To pop value from back of the queue\n$ pop_back\n";
    cout<<"To display the element at front of queue \n$ front\n";
    cout<<"To display the element at rear of queue \n$ rear\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    
    while(true)
    {
    	cin>>op;
    	if (op=="push_front")
    	{
    		cin>>val;
    		q.push_front(val);
    	}

    	else if (op=="push_back")
    	{
    		cin>>val;
    		q.push_back(val);
    	}

    	else if (op=="pop_back")
    	{
    		int k = q.pop_back();
    		if (k==INT_MAX)
    		{
    			cout<<"Queue underflow :/\n";
    		}
    		else
    		{
    			cout<<k<<" popped from back of queue\n";
    		}
    	}

    	else if (op=="pop_front")
    	{
    		int k = q.pop_front();
    		if (k==INT_MAX)
    		{
    			cout<<"Queue underflow :/\n";
    		}
    		else
    		{
    			cout<<k<<" popped from front of queue\n";
    		}
    	}

    	else if (op=="front")
    	{
    		if (q.front()==-1)
    			cout<<"empty queue\n";
    		else
    			cout<<q.front()<<"\n";
    	}
    	else if (op=="rear")
    	{
    		if (q.rear()==-1)
    			cout<<"empty queue\n";
    		else
    			cout<<q.rear()<<"\n";
    			
    	}
		else if (op == "view")
		{
			q.display();
		}
		else if (op=="size")
		{
			cout<<q.size()<<"\n";
		}
    	else if (op=="exit")
    	{
    		break;
    	}
    }

	return 0;
}