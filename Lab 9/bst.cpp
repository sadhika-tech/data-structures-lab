//Program on Tree ADT using BST
#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value);
};

class bst 
{
    private:
        Node* root;
        Node* insert(Node* node,int value);
        void preorder(Node* node);
        void inorder(Node* node);
        void postorder(Node* node);
        bool search(Node* node,int key);

    public:
        bst()
        {
            root=NULL;
        };
        void insert(int value);
        void preorder();
        void inorder();
        void postorder();
        bool search(int key);
};

int main() 
{
    bst tree;
    int choice,value;

    while(choice!=6) 
    {
        //Printing Menu Loop
        cout<<"\nMenu Card: ";
        cout<<"\n1: To insert an element";
        cout<<"\n2: For preorder traversal";
        cout<<"\n3: For inorder traversal";
        cout<<"\n4: For postorder traversal";
        cout<<"\n5: To search for an element";
        cout<<"\n6: To exit the program";
        cout<<"\nenter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>value;
                tree.insert(value);
                break;

            case 2:
                cout<<"Preorder Traversal: ";
                tree.preorder();
                break;

            case 3:
                cout<<"Inorder Traversal: ";
                tree.inorder();
                break;

            case 4:
                cout<<"Postorder Traversal: ";
                tree.postorder();
                break;

            case 5:
                cout<<"Enter value to search: ";
                cin>>value;
                if(tree.search(value)) 
                {
                    cout<<"Element found!\n";
                }
                else 
                {
                    cout<<"Element not found!\n";
                }
                break;

            case 6:
                cout<<"Exiting the program\n";
                return 0;

            default:
                cout<<"Invalid option.\n";
        }
    }
    return 0;
}

Node::Node(int value) 
{
    data=value;
    left=right=nullptr;
}

//Defining insert function

Node* bst::insert(Node* node,int value) 
{
    if(node==nullptr) 
    {
        return new Node(value);
    }
    if(value<node->data) 
    {
        node->left=insert(node->left,value);
    }
    else
    {
        node->right=insert(node->right,value);
    }
    return node;
}

void bst::insert(int value) 
{
    root=insert(root,value);
}

// Defining Preorder traversal
void bst::preorder(Node* node) 
{
    if(node!=nullptr) 
    {
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}

void bst::preorder() 
{
    preorder(root);
    cout<<endl;
}

// Deefining Inorder traversal
void bst::inorder(Node* node) 
{
    if(node!=nullptr) 
    {
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}

void bst::inorder() 
{
    inorder(root);
    cout<<endl;
}

// Defining DPostorder traversal
void bst::postorder(Node* node) 
{
    if(node!=nullptr) 
    {
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
}

void bst::postorder() 
{
    postorder(root);
    cout<<endl;
}

// Defining Search function
bool bst::search(Node* node,int key) 
{
    if(node==nullptr) 
    {
        return false;
    }
    if(node->data==key) 
    {
        return true;
    }
    else if(key<node->data) 
    {
        return search(node->left,key);
    }
    else 
    {
        return search(node->right,key);
    }
}

bool bst::search(int key) 
{
    return search(root,key);
}