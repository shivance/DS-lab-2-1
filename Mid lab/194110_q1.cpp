#include <iostream>
#include <climits>

using namespace std;

#define MAX 10

class int_Deque
{
	int siz,f,r;
	int capacity;
	int arr[MAX];
public:
	int_Deque()
	{
		capacity = MAX;
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

	bool push_back(int data)
	{
		if (siz==capacity)
			//Overflow in push attempt;
			return false;


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
		return true;
	}

	bool push_front(int data)
	{
		if (siz== capacity)
			return false;

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
		return true;
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
			return;
		
		if (f<=r)
		{
			cout<<"FRONT -> ";
			for (int i=f;i<=r;++i)
			{
				cout<<arr[i]<<" ";
			}
			cout<<" <-REAR";
			cout<<endl;
		}
		else
		{
			for (int i=f;i<capacity;++i)
				cout<<arr[i]<<" ";

			for (int i=0;i<=r;++i)
				cout<<arr[i]<<" ";

			cout<<endl;
		}
	}
};


class priQueue{
public:	
	int_Deque q;

	bool EnQue(int v){
		if (v >= q.front()){
			q.push_front(v);
			return true;
		}
		if (v <= q.rear()){
			q.push_back(v);
			return true;
		}

		int a = q.pop_back();
		EnQue(v);
		q.push_back(a);
	}

	int DeQue(){
		return q.pop_front();
	}
	

	void Print(){
		q.display();
	}

};




int main()
{
	priQueue pq;
	
    int op;int v;bool flg;
    
    
    
    while(true)
    {
    	cout<<"1. EnQue 2. DeQue 3. Print 4. Exit : ";
    	cin>>op;cout<<"\n";
    	if (op==1)
    	{
    		cout<<"EnQue: ";
    		cin>>v;
    		pq.EnQue(v);
    		cout<<"\n";
    	}

    	else if (op==2)
    	{
    		cout<<"DeQue: ";
    		cin>>v;
    		pq.DeQue();
    	}

    	else if (op==3)
    	{
    		cout<<"int_Deque Contents : ";
    		pq.Print();
    	}
    	

    	else
    		break;

    }
   

	return 0;
}