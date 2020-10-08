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

void deletenode(node* head,int dt)
{
	node* tmp = head;
	if (head->data==dt)
	{
		head = head->next;
		tmp->next = NULL;
		free(tmp);
		return;
	}

	else{
		if (head->next==NULL)
		{
			cout<<"NOT FOUND\n";
			return;
		}
		else{
			prev = head;
			tmp = head->next;
			while(tmp->next != NULL)
			{
				if (tmp->data == dt)
				{
					prev->next = tmp->next;
					tmp->next = NULL;
					free(tmp);
				}
				else
				{
					prev = tmp;
					tmp = tmp->next;
				}
			}

			if (tmp->next == NULL)
			{
				cout<<"NOT FOUND\n";
				return ;
			}
		}
	}
}

void insertAfter(node* tmp,int dt)
{
	node* newnode = new node();
	newnode->data = dt;
	newnode->next = tmp->next;
	tmp->next = newnode;
}

int main()
{
	node* head , end;
	head = NULL;
	int a;
	cin>>a;
	head = new node();
	head->dt = a;

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
			cnt++;
			tmp = new node();
			tmp->dt = a;
			prev->next = tmp;
			prev = tmp;
		}

		if (cnt==5)
		{
			fifth = tmp;
		}

	}
}