#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

class dllnode
{
public:
	int data;dllnode* prev,*next;
	node()
	{
		prev = next = NULL;
	}
};


void push_front(dllnode* front)
{
	int val;cin>>val;
	dllnode* tmp = new dllnode();
	tmp->data = val;
	tmp->next = front;
	front->prev = tmp;
	// tmp - front - ......... - back
	front = tmp;
}

void push_back(dllnode* back)
{
	int val; cin>>val;
	// front - ........... - back - tmp
	dllnode* tmp = new dllnode();
	tmp->prev = back;
	back->next = tmp;

	back = tmp;
}

void pop_front(dllnode* &front)
{
	if (front==NULL)
	{
		cout<<"list overflow\n";
		return;
	}
	dllnode* tmp = front;
	cout<<tmp->data<<" popped from front\n";
	front = front->next;
	front->prev = NULL;
	tmp->next = NULL;
	free(tmp);
}

void pop_back(dllnode* &back)
{
	if (back==NULL)
	{
		cout<<"list overflow\n";
		return;
	}
	dllnode* tmp = back;
	cout<<tmp->data<<" popped from back\n";
	back = back->prev;
	back->next = NULL;
	tmp->prev = NULL;
	free(tmp);
}

void display(dllnode* front , dllnode* back)
{
	dllnode* tmp = front;
	while(tmp->next!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

int main()
{
    string op;int k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the linkedlist : "<<"\n";
    cout<<"To push integer <val> at front of list:\n$ push_front <val>\n ";
    cout<<"To push integer <val> at back of list:\n$ push_back <val>\n ";
    cout<<"To pop value from front of list\n$ pop_front\n";
    cout<<"To pop value from back of list:\n$ pop_back\n";
    cout<<"To display the content of list \n$ view\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    dllnode* front , *back;
    front = back = NULL;
    
    while(true)
    {
    	cin>>op;
    	if (op=="push_front")
    	{
    		push_front(front);
    	}
    	else if (op=="push_back")
    	{
    		push_back(back);
    	}
    	else if (op=="pop_front")
    	{
    		pop_front(front);
    	}
    	else if (op=="pop_back")
    	{
    		pop_front(back);
    	}
    	else if (op=="view")
    	{
    		display(front,back);
    	}
    	else if (op=="exit")
    	{
    		break;
    	}
    }

	return 0;


