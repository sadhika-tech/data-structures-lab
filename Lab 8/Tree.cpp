//Program on Tree ADT
#include<iostream>
using namespace std;

class treenode 
{
public:
    char data;
    treenode* left,*right;
    
    treenode(char value) 
    {
        data=value;
        left=right=nullptr;
    }
};

class binarytree 
{
    public:
        treenode* root;
    
        binarytree() 
        { 
            root=nullptr; 
        }

        treenode* insert(treenode* node,char value);
        void preorder(treenode* node);
        void inorder(treenode* node);
        void postorder(treenode* node);
        bool search(treenode* node,char key);
        treenode* rotateleft(treenode* node);
        treenode* rotateright(treenode* node);
};

int main() {
    binarytree tree;
    int choice;
    char value;
    
    while(choice!=8) 
    {
        //Printing Menu Card
        cout<<"\nMenu Card: ";
        cout<<"\n1: To insert an element";
        cout<<"\n2: For preorder traversal";
        cout<<"\n3: For inorder traversal";
        cout<<"\n4: For postorder traversal";
        cout<<"\n5: To search for an element";
        cout<<"\n6: To rotate left";
        cout<<"\n7: To rotate right";
        cout<<"\n8: To exit the program";
        cout<<"\nenter your choice: ";
        cin>>choice;
        
        switch(choice) 
        {
            case 1:
                cout<<"enter character to insert: ";
                cin>>value;
                tree.root=tree.insert(tree.root,value);
                break;
            
            case 2:
                cout<<"preorder: ";
                tree.preorder(tree.root);
                cout<<endl;
                break;
            
            case 3:
                cout<<"inorder: ";
                tree.inorder(tree.root);
                cout<<endl;
                break;
            
            case 4:
                cout<<"postorder: ";
                tree.postorder(tree.root);
                cout<<endl;
                break;
            
            case 5:
                cout<<"enter character to search: ";
                cin>>value;
                cout<<(tree.search(tree.root,value) ? "found" : "not found")<<endl;
                break;
            
            case 6:
                tree.root=tree.rotateleft(tree.root);
                cout<<"left rotation performed\n";
                break;
            
            case 7:
                tree.root=tree.rotateright(tree.root);
                cout<<"right rotation performed\n";
                break;
            
            case 8:
                cout<<"Exiting th e program\n";
                break;
                
            default:
                cout<<"invalid choice, try again!\n";
        }
    }
}

//Defining the insert function

treenode* binarytree::insert(treenode* node,char value) 
{
    if(!node) return new treenode(value);
    
    cout<<"insert "<<value<<" to left or right of "<<node->data<<"? (l/r): ";
    char choice;
    cin>>choice;
    
    if(choice=='l')
    {
        node->left=insert(node->left,value);
    }
    else 
    {
        node->right=insert(node->right,value);
    }
    return node;
}

//Defining the preorder function

void binarytree::preorder(treenode* node) 
{
    if(!node)
    {
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

//Defining the inorder function

void binarytree::inorder(treenode* node) 
{
    if(!node) 
    {
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

//Defining the postorder function

void binarytree::postorder(treenode* node) 
{
    if(!node) 
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

//Defining the search function

bool binarytree::search(treenode* node,char key) 
{
    if(!node) 
    {
        return false;
    }
    if(node->data==key) 
    {
        return true;
    }
    return search(node->left,key)||search(node->right,key);
}

//Defining the rotate left function

treenode* binarytree::rotateleft(treenode* node) 
{
    if(!node||!node->right) 
    {
        return node;
    }
    treenode* newroot=node->right;
    node->right=newroot->left;
    newroot->left=node;
    return newroot;
}

//Defining the rotate right function

treenode* binarytree::rotateright(treenode* node) 
{
    if(!node||!node->left) 
    {
        return node;
    }
    treenode* newroot=node->left;
    node->left=newroot->right;
    newroot->right=node;
    return newroot;
}
