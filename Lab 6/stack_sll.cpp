//Program on Stack ADT using singly linked list
#include <iostream>
#include<cstdlib>
using namespace std;

class node 
{
public:
    char data;
    node* next;
    
    node(char value) 
    {
        data = value;
        next = nullptr;
    }
};

class stack 
{
    private:
        node* top;

    public:
        stack() 
        { 
            top=NULL; 
        }
        bool isempty();
        void push(char);
        void pop();
        void peek();
};

int main() 
{
    stack stack;
    int choice;
    char ch;

    while(choice!=4)
    {
        //Printing Menu Card
        cout<<"\n\nMenu Card:\n";
        cout<<"1: To push an element into the stack\n";
        cout<<"2: To pop an element from the stack\n";
        cout<<"3: To peek at the first element of the stack\n";
        cout<<"4: To exit the program\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";

        switch (choice) 
        {
            case 1:
                cout<<"Enter a character to push: ";
                cin>>ch;
                stack.push(ch);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout<<"Exiting the program\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }

    return 0;
}

//Defining if the stack is empty condition

bool stack::isempty() 
{
    return top==NULL;
}

//Defining push function

void stack::push(char ch) 
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=ch;
    newnode->next = top;
    top=newnode;
    cout<<"Pushed: "<<ch;
}

//Defining pop function

void stack::pop() 
{
    if (isempty()) 
    {
        cout << "Stack is empty.\n";
    } 
    else 
    {
        node* temp=top;
        cout<<"Popped: "<<top->data;
        top=top->next;
        free(temp);
    }
}

//Defining peek function

void stack::peek() 
{
    if (isempty()) 
    {
        cout<<"Stack is empty.\n";
    } 
    else
    {
        cout<<"Top element: "<<top->data;
    }
}