#include <iostream>
#include <cstdlib>
using namespace std;

//Declaring llist node

struct Node{
    int data;
    struct Node* link;
};

struct Node* top;

// Utility functions for stack

void push(int data)
{
    struct Node* temp;
    temp = new Node();

    //checking if stack is empty ?
    if (!temp){
        cout<<"\nStack Overflow";
        exit(1);
    }

    temp -> data = data;

    //put top pointer reference into temp link
    temp -> link = top;

    //making temp as top of Stack
    top = temp;
}

int isempty()
{
    return top == NULL;
}

int peek()
{
    if (!isempty())
        return top->data;
    
    else
        exit(1);
}

void pop(){
    struct Node* temp;

    if (top==NULL){
        cout<<"Stack underflow";
        exit(1);
    } 
    else{
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display(){
    struct Node* temp;
    if (isempty()) cout<<"Stack is empty";
    else{
        temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->link;
        }
    }
}

int main(){
    push(1);
    push(2);
    display();

    return 0;
}