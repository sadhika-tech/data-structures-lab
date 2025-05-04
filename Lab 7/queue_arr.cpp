//Menu driven program on Queue ADT array of max size 5
#include<iostream>
#define size 5
using namespace std;

class queue
{
    private:

    int arr[size];
    int front,rear;

    public:
    queue()
    {
        front=-1;
        rear=-1;
    };

    bool full();
    bool empty();
    int enqueue(int);
    int dequeue();
    int peek();
    void display();
};

int main()
{
    queue queue;
    int choice;
    int value;

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
        

        switch(choice)
        {
            case 1:
                cout<<"Enter an elemnet to add at the back: ";
                cin>>value;
                cout<<queue.enqueue(value);
                break;
                
            case 2:
                cout<<"The element removed: ";
                cout<<queue.dequeue();
                break;
                
            case 3:
                cout<<"The element at the front: "<<queue.peek();
                break;

            case 4:
                queue.display();
                break;

            case 5:
                cout<<"Exiting the program\n";
                break;

            default:
                cout<<"Invalid option";
                break;
        }
    }

    return 0;
}

//Defining is full function

bool queue::full()
{
    return rear==size-1;
}

bool queue::empty()
{
    return front ==-1;
}

//Defining enqueue function

int queue::enqueue(int value)
{
    if (full())
    {
        return 0;
    }
    if(front==-1)
    {
        front=0;
    }
    arr[++rear]=value;
    return 1;

}

//Defining dequeue function

int queue::dequeue()
{
    if(empty())
    {
        return 0;
    }
    int val=arr[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    return val;
}

//Defining peek function
int queue::peek()
{
    if(empty())
    {
        return 0;
    }
    return arr[front];
}

//Defining display function

void queue::display()
{
    if (empty())
    {
        cout<<"Queue is empty";
        return;
    }
    cout<<"The array: ";
    for(int i=front; i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

