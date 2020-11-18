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


dllnode* push_front(dllnode* front,dllnode* &back)
{
	int val;cin>>val;
	dllnode* tmp = new dllnode();
	tmp->data = val;
	if (front == NULL && back==NULL)
	{
		back = tmp;
		front = tmp;
		return front;
	}
	tmp->next = front;
	front->prev = tmp;
	// tmp - front - ......... - back
	return tmp;
}

dllnode* push_back(dllnode* &front,dllnode* back)
{
	int val; cin>>val;
	dllnode* tmp = new dllnode();
	tmp->data = val;
	if (front == NULL && back==NULL)
	{
		front = tmp;
		back = tmp;
		return back;
	}
	tmp->prev = back;
	back->next = tmp;
	// front - ........... - back - tmp
	return tmp;
}

dllnode* pop_front(dllnode* front,dllnode *&back)
{
	if (front==NULL)
	{  
		cout<<"list overflow\n";
		return NULL;
	}

	if (front->next==NULL)
	{
		// last node
		cout<<front->data<<" popped from list\n";
		free(front);
		back = NULL;
		return NULL;
	}
	dllnode* tmp = front;
	cout<<tmp->data<<" popped from front\n";
	front = front->next;
	front->prev = NULL;
	tmp->next = NULL;
	free(tmp);

	return front;
}

dllnode* pop_back(dllnode*& front,dllnode* back)
{
	if (back==NULL)
	{
		cout<<"list overflow\n";
		return NULL;
	}

	if (back->prev == NULL)
	{
		// last node
		cout<<back->data<<" popped from list\n";
		free(back);
		front = NULL;
		return NULL;
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
	if (front == NULL && back == NULL)
	{
		cout<<"Empty list\n";
		return;
	}
	dllnode* tmp = front;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
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
    		front = push_front(front,back);
    	}
    	else if (op=="push_back")
    	{
    		back = push_back(front,back);
    	}
    	else if (op=="pop_front")
    	{
    		front = pop_front(front,back);
    	}
    	else if (op=="pop_back")
    	{
    		back = pop_back(front,back);
    	}
    	else if (op=="view")
    	{
    		display(front,back);
    	}
    	else if (op=="exit")
    	{
    		break;
    	}
    	else
    	{
    		cout<<"Invalid input\n";
    		break;
    	}
    }

	return 0;
}

