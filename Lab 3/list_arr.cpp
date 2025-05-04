#include<iostream>
#include<algorithm>
#define MAX 5
using namespace std;
//Defining class
class List
{
    public:

    int arr[MAX];
    int size;

    List()
    {
        size=0;
    }

    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int delbeg();
    int delend();
    int delpos(int);
    int search(int);
    int rotate(int);
    void display();

};

int main()
{
    int choice;
    List list;
    int value;
    int pos;
    int k;

    while(choice!=10)
    {
        //Menu loop
        cout<<"\n1: Insert beginning";
        cout<<"\n2: Insert end";
        cout<<"\n3: Insert at position";
        cout<<"\n4: Delete beginning";
        cout<<"\n5: Delete end";
        cout<<"\n6: Delete at position";
        cout<<"\n7: Search";
        cout<<"\n8: Rotate";
        cout<<"\n9: Display";
        cout<<"\n10: Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter the value to insert: ";
                cin>>value;
                cout<<list.insertbeg(value);
                break;
            
            case 2:
                cout<<"Enter the value to insert: ";
                cin>>value;
                cout<<list.insertend(value);
                break;

            case 3:
                cout<<"Enter the value to insert: ";
                cin>>value;
                cout<<"Enter the position to insert on: ";
                cin>>pos;
                cout<<list.insertpos(value,pos);
                break;

            case 4:
                cout<<list.delbeg();
                break;

            case 5:
                cout<<list.delend();
                break;

            case 6:
                cout<<"Enter the index position to delete: ";
                cin>>pos;
                cout<<list.delpos(pos);
                break;

            case 7:
                cout<<"\nEnter a value to search: ";
                cin>>value;
                cout<<list.search(value);
                break;

            case 8:
                cout<<"Enter number of timed to rotate: ";
                cin>>k;
                cout<<list.rotate(k);
                break;

            case 9:
                cout<<"The list : ";
                list.display();
                break;

            case 10:
                cout<<"Exiting the program";
                break;

            default:
                cout<<"Invalid option. Try again";
                break;

        }
    }

}

//Insert at the beginning function
int List::insertbeg(int value)
{
    if(size == MAX)
    {
        return 0;
    }
    for(int i=size;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    size++;
    return 1;
}

//Insert at the end function
int List::insertend(int value)
{
    if(size == MAX)
    {
        return 0;
    }
    arr[size]=value;
    size++;
    return 1;
}

//Insert at a position
int List::insertpos(int value,int pos)
{
    if(size == MAX||pos<0||pos>=size)
    {
        return 0;
    }
    for(int i=size;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    size++;
    return 1;
}

//Delete the beginning element
int List::delbeg()
{
    if(size==0)
    {
        return 0;
    }
    int a=arr[0];
    for(int i=0;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    return a;
}

//Delete the end element
int List::delend()
{
    if(size==0)
    {
        return 0;
    }
    int a=arr[size-1];
    size--;
    return a;
}

//Delete the element at a position
int List::delpos(int pos)
{
    if(size==0||pos<0||pos>size)
    {
        return 0;
    }
    int a=arr[pos];
    for(int i=pos;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    return a;
}

//Search an element
int List::search(int value)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }        
    }
    return 0;
}

//Display the list
void List::display()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//Rotate the list 
int List::rotate(int k)
{
    if(size==0)
    {
        return 0;
    }
    k=k%size;
    reverse(arr,arr+size);
    reverse(arr,arr+k);
    reverse(arr+k,arr+size);

    return 1;

}