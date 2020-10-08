#include <iostream>
#include <cstdlib>
#include <climits>

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

node* push(node* rear)
{
	int val;cin>>val;
	node* tmp = new node();
	tmp->data = val;
	tmp->next = rear;
	return tmp;
}

node* pop(node* &front)
{
	if (front->next==NULL)
	{
		free(front)
		return NULL;
	}
	else
	{

	}
}