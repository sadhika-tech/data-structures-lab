//Program on Stack ADT using array with max size 5
#include <iostream>
#define SIZE 5
using namespace std;

class stack 
{
    private:
        char arr[SIZE];
        int top;

    public:
        stack() 
        { 
            top = -1; 
        }

        bool isFull();
        bool isEmpty();
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

        switch(choice) 
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
                break;
        }
    } 

    return 0;
}

//Defining if the stack is full condition

bool stack::isFull() 
{
    return top==SIZE-1;
}

//Defining if the stack is empty condition

bool stack::isEmpty() 
{
    return top==-1;
}

//Defining push function

void stack::push(char ch) 
{
    if (isFull()) 
    {
        cout<<"Stack is full.\n";
    } 
    else 
    {
        arr[++top]=ch;
        cout<<"Pushed: "<<ch;
    }
}

//Defining pop function

void stack::pop() 
{
    if (isEmpty()) 
    {
        cout<<"Stack is empty.\n";
    } 
    else 
    {
        cout<<"Popped: "<<arr[top--];
    }
}

//Defining peek function

void stack::peek() 
{
    if (isEmpty()) 
    {
        cout << "Stack is empty.\n";
    } 
    else 
    {
        cout<<"Top element: "<<arr[top];
    }
}