//Program on Queue using linked list
#include <iostream>
using namespace std;

struct node 
{
    int data;
    node* next;

    node(int value) 
    {
        data=value;
        next=nullptr;
    }
};

class queue 
{
    private:
        node* front;
        node* rear;
    
    public:
        queue()
        {
            front=rear=nullptr;
        }
        bool empty();
        int enqueue(int);
        int dequeue();
        int peek();
};


int main() 
{
    queue q;
    int choice,value;

    while(choice!=4)
    {
        //Printing menu card
        cout<<"\n\nMenu Card: ";
        cout<<"\n1: To enqueue an element at the end";
        cout<<"\n2: To dequeue an element from the front";
        cout<<"\n3: To peek at the beginning element";
        cout<<"\n4: To exit a program";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch (choice) 
        {
            case 1:
                cout<<"Enter an element to enqueue: ";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                value=q.dequeue();
                if (value!=-1)
                    cout<<"dequeued: "<<value<<"\n";
                break;
            case 3:
                value=q.peek();
                if (value!=-1)
                    cout<<"Front element: "<<value<<"\n";
                break;
            case 4:
                cout<<"Exiting the program.\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    }

    return 0;
}

// Defining queue is empty function

bool queue::empty() 
{
    return front==nullptr;
}

// Defining enqueue operation

int queue::enqueue(int value) 
{
    node* newnode=new node(value);

    if (empty()) 
    {
        front=rear=newnode;
    } 
    else 
    {
        rear->next=newnode;
        rear=newnode;
    }

    return 1;
}

// Defining dequeue operation

int queue::dequeue() 
{
    if (empty()) 
    {
        return -1;
    }

    node* temp=front;
    int value=temp->data;
    front=front->next;

    if (front==nullptr) 
    {
        rear=nullptr;
    }

    delete temp;
    return value;
}

// Defining peek operation

int queue::peek() 
{
    if (empty()) 
    {
        return -1;
    }
    return front->data;
}
