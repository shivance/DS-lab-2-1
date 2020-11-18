#include <iostream>
#include <climits>
#include <cstdlib>
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

void print(node* head)
{
	node* tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

bool deletenode(node* &head,int pos)
{
	// delete nth node
	//int pos
	//cout<<"Enter the index of node to be deleted\n";
	//cin>>pos;
	node* tmp = head,*tmpn;

	int i=1;
	if (pos == 1)
	{
		head = head->next;
		tmp->next = NULL;
		free(tmp);
	}
	else{
		while(tmp!=NULL)
		{
			if (i==pos-1) 
			{
				if (tmp->next!=NULL)
				{
					tmpn = tmp->next;
					tmp->next = tmpn->next;
					tmpn->next = NULL;
					free(tmpn);
				}
				else{
					cout<<"reqd node doesn't exist\n";
				}
				return true;
			}
			++i;
		}
	}
}

bool insertAt(node* &head,int dt,int pos)
{
	node* tmp = head;
	node* newnode = new node();
	newnode->data = dt;
	int i=1;
	if (pos == 1)
	{
		newnode->next = head;
		head = newnode;
	}
	else{
		while(tmp!=NULL)
		{
			if (i==pos-1) 
			{
				newnode->next = tmp->next;
				tmp->next = newnode;
				return true;
			}
			++i;
		}

		return false;
	}
}


void push_end(node* head,int val)
{
	//adds element at the end of list
	node* newnode = new node();
	newnode->data = val;

	node* tmp = head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next = newnode;
}

void push_front(node* &head,int val)
{
	insertAt(head,val,1);
}

void pop_front(node* &head)
{
	deletenode(head,1);
}

void pop_end(node* &head)
{
	node* tmp = head;
	while(tmp->next->next!=NULL)
	{
		tmp = tmp->next;
	}
	node* tmpn = tmp->next;
	tmp->next=NULL;
	free(tmpn);

}



void display(node* head)
{
	node* tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}


int main()
{
	node* head , end;
	head = NULL;
	int a;
	cin>>a;
	head = new node();
	head->data = a;

	node* prev = head;
	node* tmp;

	while(true)
	{
		cin>>a;
		
		if (a==-1)
		{
			break;
		}

		else
		{
			tmp = new node();
			tmp->data = a;
			prev->next = tmp;
			prev = tmp;
		}

	}

	push_end(head,8);
	display(head);
	push_front(head,9);
	display(head);
	pop_front(head);
	display(head);
	pop_end(head);
	display(head);
	deletenode(head,2);
	display(head);
	insertAt(head,12,2);
	display(head);

	return 0;
	
}