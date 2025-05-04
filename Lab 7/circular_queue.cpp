//Program on Circular Queue ADT
#include <iostream>
#define SIZE 5

using namespace std;

class queue 
{
    private:
        int arr[SIZE];
        int front,rear;
        
    public:
        queue() 
        {
            front=-1;
            rear=-1;
        }

        bool isFull();
        bool isEmpty();
        int enqueue(int);
        int dequeue();
        int peek();
        void display();
};

int main() 
{
    queue queue;
    int choice,value;

    while(choice!=5)
    {
        //Printing menu card
        cout<<"\n\nMenu Card: ";
        cout<<"\n1: To enqueue an element at the end";
        cout<<"\n2: To dequeue an element from the front";
        cout<<"\n3: To peek at the beginning element";
        cout<<"\n4: To display the array";
        cout<<"\n5: To exit a program";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;

        switch (choice) 
        {
            case 1:
                cout<<"Enter an element to enqueue: ";
                cin>>value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                value=queue.peek();
                if (value!=-1)
                    cout<<"Front element: "<<value<<"\n";
                break;
            case 4:
                queue.display();
                break;
            case 5:
                cout<<"Exiting the program.\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    }

    return 0;
}

// Deefining full function

bool queue::isFull() 
{
    return (rear+1)%SIZE==front;
}

// Defining empty function

bool queue::isEmpty() 
{
    return front==-1;
}

// Defining Enqueue operation

int queue::enqueue(int value) 
{
    if (isFull()) 
    {        
        return 0;
    }
    
    if (isEmpty()) 
    {
        front=rear=0;
    } 
    else 
    {
        rear=(rear+1)%SIZE;
    }

    arr[rear]=value;
    return 1;
}

// Defining Dequeue operation

int queue::dequeue() 
{
    if (isEmpty()) 
    {
        return 0;
    }

    int value=arr[front];
    
    if (front==rear) 
    { 
        front=rear=-1;
    } 
    else 
    {
        front=(front+1)%SIZE;
    }

    return value;
}

// Defining Peek operation

int queue::peek() 
{
    if (isEmpty()) 
    {
        return -1;
    }
    return arr[front];
}

// Display queue elements

void queue::display() 
{
    if (isEmpty()) 
    {
        cout<<"Queue is empty!\n";
        return;
    }

    cout<<"The array: ";
    int i=front;
    while(true) 
    {
        cout<<arr[i]<<" ";
        if (i==rear)
        {
            break;
        }
        i=(i+1)%SIZE;
    }
    cout<<"\n";
}