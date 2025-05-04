//Program to implement Hash ADT using separate chaining
#include <iostream>
#include <cstdlib>
using namespace std;

struct node 
{
    int data;
    node* next;
};

class hashtable 
{
    private:
        int tablesize;
        node** table;

        int hashfunction(int key);

    public:
        hashtable(int size)
        {
            tablesize=size;
            table=(node**)malloc(tablesize*sizeof(node*));
            for(int i=0;i<tablesize;i++)
                table[i]=nullptr;
        };

        void insert(int key);
        void remove(int key);
        void search(int key);
        void display();
};

int main() 
{
    int size, choice, key;

    cout<<"enter the size of the hash table: ";
    cin>>size;

    hashtable ht(size);

    while(choice!=5)
    {
        //Printing Menu Loop
        cout<<"\nMenu Card\n";
        cout<<"1. To insert an element\n";
        cout<<"2. To delete an element\n";
        cout<<"3. To search for an element\n";
        cout<<"4. To display the list\n";
        cout<<"5. To exit the program\n";
        cout<<"enter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            case 1:
                cout<<"enter key to insert: ";
                cin>>key;
                ht.insert(key);
                break;
            case 2:
                cout<<"enter key to delete: ";
                cin>>key;
                ht.remove(key);
                break;
            case 3:
                cout<<"enter key to search: ";
                cin>>key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout<<"exiting the program\n";
                break;
            default:
                cout<<"invalid choice\n";   
        }
    }

    return 0;
}

//Defining hash function

int hashtable::hashfunction(int key) 
{
    return key%tablesize;
}

//Defining insert function

void hashtable::insert(int key) 
{
    int index=hashfunction(key);
    node* current=table[index];

    while(current!=nullptr) 
    {
        if(current->data==key) 
        {
            cout<<"key "<<key<<" already exists at index "<<index<<".\n";
            return;
        }
        current=current->next;
    }

    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=key;
    newnode->next=table[index];
    table[index]=newnode;
    cout<<"inserted key "<<key<<" at index "<<index<<".\n";
}

//Defining delete function

void hashtable::remove(int key) 
{
    int index=hashfunction(key);
    node* current=table[index];
    node* prev=nullptr;

    while(current!=nullptr) 
    {
        if(current->data==key) 
        {
            if(prev==nullptr) 
            {
                table[index]=current->next;
            } 
            else 
            {
                prev->next=current->next;
            }
            free(current);
            cout<<"deleted key "<<key<<" from index "<<index<<".\n";
            return;
        }
        prev=current;
        current=current->next;
    }

    cout<<"key "<<key<<" not found in the table.\n";
}

//Defining searcch function

void hashtable::search(int key) 
{
    int index=hashfunction(key);
    node* current=table[index];

    while(current!=nullptr) 
    {
        if(current->data==key) 
        {
            cout<<"key "<<key<<" found at index "<<index<<".\n";
            return;
        }
        current=current->next;
    }

    cout<<"key "<<key<<" not found in the table.\n";
}

//Defining display function

void hashtable::display() 
{
    cout<<"\nhash table:\n";
    for(int i=0;i<tablesize;i++) 
    {
        cout<<i<<" : ";
        node* current=table[i];
        while(current!=nullptr) 
        {
            cout<<current->data<<" -> ";
            current=current->next;
        }
        cout<<"null\n";
    }
}
