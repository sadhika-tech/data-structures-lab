//Program to implement priority queue ADT using a max heap
#include<iostream>
using namespace std;

class priority
{
    public:
    int* arr;
    int current;
    int cap;

    priority(int cap)
    {
        this->cap=cap;
        current = 0;
        arr=new int[cap];
    }

    void swap(int &a,int &b);
    void heapifyup(int);
    void heapifydown(int);

    int insertvalue(int);
    int deletevalue();
    void display();
    int search(int);
    void heapsort();
};

int main()
{
    int choice,a,cap,check;
    cout<<"Enter the capacity of the priority queue : ";
    cin>>cap;
    priority p(cap);

    while(choice!=6) 
    {
        //Printing menu loop
        cout<<"\nMenu Card";
        cout<<"\n1: To insert an element";
        cout<<"\n2: To delete the max element";
        cout<<"\n3: To display the queue";
        cout<<"\n4: To search for an element";
        cout<<"\n5: To sort the queue (heap sort)";
        cout<<"\n6: To exit the program";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter the value to be inserted : ";
                cin>>a;
                check=p.insertvalue(a);
                if(check!=0)
                cout<<a<<" inserted succesfully !!\n";
                break;

            case 2:
                check=p.deletevalue();
                if(check!=-1)
                cout<<"Deleted element is "<<check<<"\n";
                break;

            case 3:
                p.display();
                break;

            case 4:
                cout<<"Enter the value to be searched : ";
                cin>>a;
                check=p.search(a);

                if(check!=-1)
                {
                    cout<<"Target element found!!\n";
                }
                else
                {
                    cout<<"Target element not found...\n";
                }
                break;

            case 5:
                p.heapsort();
                break;

            case 6:
                cout<<"\nExiting the program...\n";
                break;

            default:
                cout<<"\nInvalid option";
                break;
        }
    }
}

//Defining swap function

void priority::swap(int &a,int &b)
{
    int temp=b;
    b=a;
    a=temp;
}

//Defining heapify up function

void priority::heapifyup(int idx)
{
    int parent=(idx-1)/2;
    while(idx>0 && arr[idx]>arr[parent])
    {
        swap(arr[idx],arr[parent]);
        idx=parent;
        parent=(idx-1)/2;
    }
}

//Defining heapifydown function
void priority::heapifydown(int idx) 
{
    int left, right, largest;
    while (true) 
    {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        largest = idx;

        if (left < current && arr[left] > arr[largest]) 
        {
            largest = left;
        }

        if (right < current && arr[right] > arr[largest]) 
        {
            largest = right;
        }

        if (largest == idx) 
        {
            break;
        }

        swap(arr[idx], arr[largest]);
        idx = largest;
    }
}


//Defining insert function

int priority::insertvalue(int a)
{
    if(current==cap)
    {
        cout<<"Queue is full already!!\n";
        return 0;
    }
    arr[current]=a;
    heapifyup(current);
    current++;
    return 1;

}

//Defining delete function
int priority::deletevalue()
{
    if(current==0)
    {
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int a=arr[0];
    arr[0]=arr[current-1];
    heapifydown(0);
    current--;
    return a;

}

//Defining display function

void priority::display()
{
    if (current== 0) 
    {
        cout << "Queue is empty!!\n";
        return;
    }

    for (int i = 0; i < current; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

//Defining search function

int priority::search(int a)
{
    for(int i=0;i<current;i++)
    {
        if(arr[i]==a)
        return 1;
    }
    return -1;

}

//Defining heapsort function

void priority::heapsort()
{
    if(current==0)
    {
        cout<<"The queue is empty!!";
        return;
    }
    priority temp(cap);
    for (int i = 0; i < current; i++) 
    {
        temp.insertvalue(arr[i]);
    }

    cout << "Sorted elements in descending order: ";
    while (temp.current > 0) 
    {
        cout << temp.deletevalue() << " ";
    }
    cout << endl;
}
