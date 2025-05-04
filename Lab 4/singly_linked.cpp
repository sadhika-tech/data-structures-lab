//Program on List ADT singly linked list
#include<iostream>
using namespace std;

class list
{
    private:
    typedef struct node
    {
        int data;
        node* next;
    }node;
    node* head;

    public:
    list()
    {
        head=NULL;
    }

    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
    void displayrev();
    int revlink();

};

int main()
{
    list list;
    int choice;
    int value;
    int pos;
    while(choice!=11)
    {
        //Printing the menu card
        cout<<"\n1: To insert element at the beginning";
        cout<<"\n2: To insert element at the end";
        cout<<"\n3: To insert element at position";
        cout<<"\n4: To delete element at beginning";
        cout<<"\n5: To delete element at end";
        cout<<"\n6: To delete element at position";
        cout<<"\n7: To search for an element";
        cout<<"\n8: To display the list";
        cout<<"\n9: To display the reverse list";
        cout<<"\n10: To reverse the link";
        cout<<"\n11: Exit";
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
                cout<<list.deletebeg();
                break;

            case 5:
                cout<<list.deleteend();
                break;

            case 6:
                cout<<"Enter the index position to delete: ";
                cin>>pos;
                cout<<list.deletepos(pos);
                break;

            case 7:
                cout<<"\nEnter a value to search: ";
                cin>>value;
                cout<<list.search(value);
                break;

            case 8:
                cout<<"The list : ";
                list.display();
                break;

            case 9:
                cout<<"The list in reverse: ";
                list.displayrev();
                break;

            case 10:
                cout<<list.revlink();
                break;

            case 11:
                cout<<"Exiting the program";
                break;

            default:
                cout<<"Invalid option. Try again";
                break;

        }
    }

}

//Defining Insertion at the beginning function

int list::insertbeg(int value)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;

    return 1;
}

//Defining Insertion at the end function

int list::insertend(int value)
{
    if(head==NULL)
    {
        insertbeg(value);
        return 1;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;

    return 1;
}

//Defining insertion at a position function

int list::insertpos(int value,int pos)
{
    if(head==NULL)
    {
        insertbeg(value);
        return 1;
    }
    if(pos<0)
    {
        return 0;
    }
    int i=1;
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    node* temp=head;
    while(i<pos-1||temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}

//Defining deletion at the beginning function

int list::deletebeg()
{   
    if(head==NULL)
    {
        return 0;
    }
    node* temp=head;
    int val=temp->data;
    head=temp->next;
    free(temp);
    return val;
}

//Defining deletion at the end function

int list::deleteend()
{
    if(head==NULL)
    {
        return 0;
    }
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* del=temp->next;
    int val=del->data;
    temp->next=NULL;
    free(del);
    return val;
}

//Defining deletion at position function

int list::deletepos(int pos)
{
    if(head==NULL||pos<0)
    {
        return 0;
    }
    if(pos==1)
    {
        deletebeg();
        return 0;
    }
    node* temp=head;
    int i=1;
    while(i<pos-1&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* del=temp->next;
    int val=del->data;
    while(temp->next->next==NULL)
    {
        temp->next=NULL;
        free(del);
        return val;
    }
    temp->next=del->next;
    free(del);
    return val;
}

//Defining search function

int list::search(int value)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;

        if(temp->data==value)
        {
            return count;
        }
        temp=temp->next;
    }
    return -1;
}

//Defining display list function

void list::display()
{
    if(head==NULL)
    {
        cout<<"The list is empty\n";
        return;
    }

    node* temp=head;
    cout<<"The list is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Defining display reversed list function

void list::displayrev() 
{
    if (head==NULL) 
    {
        cout<<"List is empty";
    }
    node* temp=head;
    int count=0;
    while (temp!=NULL) 
    {
        count++;
        temp=temp->next;
    }
    node* arr[count];
    temp=head;
    for (int i=0;i<count;i++) 
    {
        arr[i]=temp;
        temp=temp->next;
    }
    for (int i=count-1;i>= 0;i--) 
    {
        cout<<arr[i]->data<<" ";
    }
}

//Defining Reverse link function

int list::revlink() 
{
    if(head==NULL)
    {
        return 0;
    }
    node* prev=NULL;
    node* temp=head;
    node* next=NULL;
    while (temp!=NULL) 
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return 1;
}
