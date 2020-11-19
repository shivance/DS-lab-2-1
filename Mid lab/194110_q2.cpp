#include <iostream>
#include <climits>

using namespace std;

class Node
{
public:
	int x,y;
	Node* next;
	bool e;
	Node(int a,int b)
	{
		x = a;
		y = b;
		e = false;
		next = NULL;
	}
};

void insert(Node**head,int a,int b)
{
	Node* newnode = new Node(a,b);
	newnode->next = (*head);
	(*head) = newnode;
}

bool update_exist(Node* &head,int a,int b)
{
	Node* tmp = head;
	while(tmp!=NULL)
	{
		if (tmp->x == b && tmp->y == a)
		{
			tmp->e = true;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void printlist(Node* head)
{
	Node* tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->x<<" "<<tmp->y<<"\n";
		tmp = tmp->next;
	}
}

void sym(Node* head)
{
	Node* tmp = head;
			while(tmp!=NULL)
			{
				if (tmp->e)
					cout<<tmp->x<<" "<<tmp->y<<"\n";
				tmp = tmp->next;
			}
}


int main()
{
	int op;
	Node* head = NULL;
	int a,b;
	while(true)
	{
		cout<<"Enter 1. Insert 2. Check pair 3. Print 4.Exit : ";
		cin>>op;
		if(op==1){		
			cin>>a>>b;
			insert(&head,a,b);
			bool o = update_exist(head,a,b);
			if (o) head->e =true;

		}
		else if (op==2)
		{
			sym(head);
		}
		else if (op == 3)
			printlist(head);
		
		else break;
	}



	return 0;
}