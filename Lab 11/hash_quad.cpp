//Program on Hash ADT using quadratic probing
#include<iostream>
using namespace std;

const int table_size=10;
const int empty=-1;
const int deleted=-2;

class hashtable 
{
    private:
        int table[table_size];

        int hashfunction(int key);

    public:
        hashtable()
        {
            for(int i=0;i<table_size;i++) 
            {
                table[i]=empty;
            }
        };
        void insert(int key);
        void remove(int key);
        void search(int key);
        void display();
};

int main() 
{
    hashtable ht;
    int choice,key;

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
                cout<<"exiting program.\n";
                break;
            default:
                cout<<"invalid choice! please try again.\n";
        }
    }

    return 0;
}

//Defining Hash function

int hashtable::hashfunction(int key) 
{
    return key%table_size;
}

//Defining insert function

void hashtable::insert(int key)
{
    int index=hashfunction(key);
    int i=0;

    while(i<table_size) 
    {
        int probe_index=(index+i*i)%table_size;
        if(table[probe_index]==empty||table[probe_index]==deleted) 
        {
            table[probe_index]=key;
            cout<<"inserted "<<key<<" at index "<<probe_index<<endl;
            return;
        }
        i++;
    }

    cout<<"hash table is full! cannot insert "<<key<<endl;
}

//Defining delte function

void hashtable::remove(int key) 
{
    int index=hashfunction(key);
    int i=0;

    while(i<table_size) 
    {
        int probe_index=(index+i*i)%table_size;
        if(table[probe_index]==key) 
        {
            table[probe_index]=deleted;
            cout<<"deleted "<<key<<" from index "<<probe_index<<endl;
            return;
        } 
        else if(table[probe_index]==empty) 
        {
            break;
        }
        i++;
    }

    cout<<"key "<<key<<" not found in the table."<<endl;
}

//Defining search function

void hashtable::search(int key) 
{
    int index=hashfunction(key);
    int i=0;

    while(i<table_size) 
    {
        int probe_index=(index+i*i)%table_size;
        if(table[probe_index]==key) 
        {
            cout<<"key "<<key<<" found at index "<<probe_index<<endl;
            return;
        } 
        else if(table[probe_index]==empty) 
        {
            break;
        }
        i++;
    }

    cout<<"key "<<key<<" not found in the table."<<endl;
}

//Defining display function

void hashtable::display() 
{
    cout<<"\nhash table:\n";
    for(int i=0;i<table_size;i++) 
    {
        if(table[i]==empty) 
        {
            cout<<i<<" : empty\n";
        } 
        else if(table[i]==deleted) 
        {
            cout<<i<<" : deleted\n";
        } 
        else 
        {
            cout<<i<<" : "<<table[i]<<"\n";
        }
    }
}
