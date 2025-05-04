//Header file for merging singly linked lists
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) : data(val), next(nullptr) {}
};

class list{
private:
    node* head;

public:
    list()
    {
        head=NULL;
    };

    void insertas(int val);
    void mergelist(list&list1,list&list2);
    void display() const;
    void clear();
};

//Defining insert ascending function

void list::insertas(int val) {
    node* newnode = new node(val);
    
    if (!head||head->data>=val) {
        newnode->next=head;
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next && temp->next->data <val) {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

// Defining merge list function

void list::mergelist(list&list1,list&list2) 
{
    node *temp1=list1.head;
    node *temp2=list2.head;
    node dummy(0);
    node* lastPtr=&dummy;

    while (temp1&&temp2) 
    {
        if (temp1->data <= temp2->data) 
        {
            lastPtr->next=new node(temp1->data);
            temp1=temp1->next;
        } 
        else 
        {
            lastPtr->next=new node(temp2->data);
            temp2=temp2->next;
        }
        lastPtr=lastPtr->next;
    }
    while (temp1!=NULL) 
    {
        lastPtr->next=new node(temp1->data);
        lastPtr=lastPtr->next;
        temp1=temp1->next;
    }

    while (temp2!=NULL) 
    {
        lastPtr->next=new node(temp2->data);
        lastPtr=lastPtr->next;
        temp2=temp2->next;
    }

    head=dummy.next;
}

// Defining display function

void list::display() const 
{
    if (!head) 
    {
        cout<<"List is empty\n";
        return;
    }
    node* temp = head;
    while (temp) 
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Defining clear function
void list::clear() 
{
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

