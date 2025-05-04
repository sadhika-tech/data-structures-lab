//Program on operations using circular linked list

#include<iostream>
#include<cstdlib>
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
    };
    int insertbeg(int);
    int insertend(int);
    int insertpos(int,int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
};

int main()
{
    list list;
    int choice;
    int value;
    int pos;

    while(choice!=9)
    {
        //Printing Menu Card
        cout<<"\nMenu Card\n";
        cout<<"1: To insert an element to the beginning\n";
        cout<<"2: To insert an element to the end\n";
        cout<<"3: To insert an element to a position\n";
        cout<<"4: To delete an element at the beginning\n";
        cout<<"5: To delete an element at the end\n";
        cout<<"6: To delete an element at a position\n";
        cout<<"7: To search for an element\n";
        cout<<"8: To display the list\n";
        cout<<"9: To exit the program\n\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter an element to insert in the beginning: ";
                cin>>value;
                cout<<list.insertbeg(value);
                break;
            
            case 2:
                cout<<"Enter an element to insert at the end: ";
                cin>>value;
                cout<<list.insertend(value);
                break;

            case 3:
                cout<<"Enter an element to insert at a position: ";
                cin>>value;
                cout<<"Enter the position to be inserted in: ";
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
                cout<<"Enter the position of the element to be deleted: ";
                cin>>pos;
                cout<<list.deletepos(pos);
                break;

            case 7:
                cout<<"Enter the element to search for: ";
                cin>>value;
                cout<<list.search(value);
                break;

            case 8:
                cout<<"The list is: ";
                list.display();
                break;
            
            case 9:
                cout<<"Exiting the program\n";
                break;

            default:
                cout<<"Invaid option.";
                break;
        }
        cout<<"\n";
    }
}

//Defining insertion at beginning function

int list::insertbeg(int value)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;

    if(head==NULL)
    {
        newnode->next=newnode;
        head=newnode;
    }
    newnode->next=head->next;
    head->next=newnode;
    return 1;
}

//Defining insertion at end function

int list::insertend(int value)
{
    insertbeg(value);
    head=head->next;
    return 1;
}

//Defining insert at a position function

int list::insertpos(int value,int pos)
{
    if(pos<=0)
    {
        return 0;
    }
    if(head==NULL||pos==1)
    {
        return insertbeg(value);
    }
    node* temp=head->next;
    int i=1;
    while(i<pos-1&&temp!=head)
    {
        temp=temp->next;
        i++;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;
    if(temp==head)
    {
        head=newnode;
    }
    return 1;
}

//Defining delete at the beginning function

int list::deletebeg()
{
    if(head==NULL)
    {
        return 0;
    }
    node* temp=head->next;
    if(head==head->next)
    {
        head=NULL;
    }

    head->next=temp->next;
    int val=temp->data;
    free(temp);
    return val;

}

//Defining delete at end function

int list::deleteend()
{
    if(head==NULL)
    {
        return 0;
    }
    if(head==head->next)
    {
        int val=head->data;
        free(head);
        head=NULL;
        return val;
    }
    node* temp=head->next;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    int val=head->data;
    free(head);
    head=temp;
    return val;

}

//Defining delete at position function

int list::deletepos(int pos)
{
    if(head==NULL||pos<=0)
    {
        return 0;
    }
    if(pos==1)
    {
        return deletebeg();
    }
    node* temp=head->next;
    node* prev=NULL;
    int i=1;
    while(i<pos&&temp!=head)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }   
    if(temp==head)
    {
        head=prev;
    }
    if(prev)
    {
        prev->next=temp->next;
    }
    int val=temp->data;
    free(temp);
    return val;
   
}

//Defining search function

int list::search(int value)
{
    int count=0;
    node* temp=head->next;
    do
    {
        count++;
        if(temp->data==value)
        {
            return count;
        }
        temp=temp->next;
    }
    while(temp!=head->next);
    return -1;
}

//Defining display function

void list::display()
{
    if(head==NULL)
    {
        cout<<"empty";
    }
    node* temp=head->next;
    do
    {
        cout<<temp->data<<" ";    
        temp=temp->next;
    }
    while(temp!=head->next);
}

