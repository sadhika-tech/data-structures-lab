//Program on Stack ADT using singly linked list
#include <iostream>
#include<cstdlib>
using namespace std;

class stack{
    public:
    typedef struct node
    {
        char data;
        node* next;
    }node;

    node* top;

    stack()
    {
        top=NULL;
    }

    int push(char);
    char pop();
    char peek();
    bool isempty();
};

//Defining if the stack is empty condition

bool stack::isempty() 
{
    return top==NULL;
}

//Defining push function

int stack::push(char ch) 
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=ch;
    newnode->next = top;
    top=newnode;
    return 1;
}

//Defining pop function

char stack::pop() 
{
    if (isempty()) 
    {
        return 0;
    } 
    else 
    {
        node* temp=top;
        char a=temp->data;
        cout<<"Popped: "<<top->data;
        top=top->next;
        free(temp);
        return a;
    }
}

//Defining peek function

char stack::peek() 
{
    if (isempty()) 
    {
        return 0;
    } 
    else
    {
        return top->data;
    }
}