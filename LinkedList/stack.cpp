#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node()
	{
		next = NULL;
	}
};

node* push(node* top)
{
	int val;
	cin>>val;
	node* tmp = new node();
	tmp->data = val;
	tmp->next = top;

	return tmp;
}

node* pop(node* &top)
{
	if (top->data == INT_MIN)
	{
		return NULL;
	}

	node* tmp = top->next;
	top->next = NULL;
	cout<<top->data<<" popped from stack\n";
	free(top);
	return tmp;
}

void display(node* top)
{
	node* tmp = top;
	cout<<"current stack is : \n";
	if (top->data>	INT_MIN)
	{
		while(tmp->data>INT_MIN)
		{
			cout<<tmp->data<<"\n";
			tmp = tmp->next;
		}
	}
	else
		cout<<"EMPTY\n";
}


int main()
{
	node* top = new node();
	node* tmp;
	top->data=INT_MIN;

	// a node to handle stack overflow

    string op;int val,k;
    cout<<"\n\n";
    cout<<"Follow below instructions to interact with the stack : "<<"\n";
    cout<<"To push integer <val> into stack :\n$ push <val>\n ";
    cout<<"To pop value from the stack\n$ pop\n";
    cout<<"To display the content of stack \n$ view\n";
    cout<<"To break the operation\n$ exit\n";
    cout<<"\n\n";
    
    while(true)
    {
    	cin>>op;
    	if (op=="push")
    	{
    		top = push(top);
    	}
    	else if (op=="pop")
    	{
    		tmp =  pop(top);
    		if (tmp==NULL) 
    		{
    			cout<<"Stack overflow\n";
    		}
    		else
    		{
    			top = tmp;
    		}

    	}
    	else if (op=="view")
    	{
    		display(top);
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