//Program on contructing construction tree
#include <iostream>
#include <stack>
using namespace std;

struct Node 
{
    char data;
    Node* left;
    Node* right;
    Node(char val)
    {
        data=val;
        left=right=nullptr;
    }
};

class exp 
{
    public:
        Node* constructTree(string postfix);
        void preorder(Node* root);
        void inorder(Node* root);
        void postorder(Node* root);
};

int main()
{
    exp tree;
    Node* root=nullptr;
    string postfix;
    int choice;

    while(choice!=6)
    {
        //Printing Menu Loop
        cout<<"\nMenu Card:\n";
        cout<<"1. Enter Postfix Expression\n";
        cout<<"2. Construct Expression Tree\n";
        cout<<"3. Preorder Traversal\n";
        cout<<"4. Inorder Traversal\n";
        cout<<"5. Postorder Traversal\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter postfix expression: ";
                cin>>postfix;
                break;

            case 2:
                root=tree.constructTree(postfix);
                cout<<"Expression Tree Constructed!\n";
                break;

            case 3:
                cout<<"Preorder: ";
                tree.preorder(root);
                cout<<"\n";
                break;

            case 4:
                cout<<"Inorder: ";
                tree.inorder(root);
                cout<<"\n";
                break;

            case 5:
                cout<<"Postorder: ";
                tree.postorder(root);
                cout<<"\n";
                break;

            case 6:
                cout<<"Exiting the program\n";
                break;

            default:
                cout<<"Invalid choice.\n";
        }
    }

    return 0;
}

//Defining consrtuct tree function

Node* exp::constructTree(string postfix)
{
    stack<Node*> st;
    for(char ch:postfix)
    {
        if(isalnum(ch))
        {
            st.push(new Node(ch));
        } 
        else 
        {
            Node* right=st.top(); st.pop();
            Node* left=st.top(); st.pop();
            Node* newNode=new Node(ch);
            newNode->left=left;
            newNode->right=right;
            st.push(newNode);
        }
    }
    return st.top();
}

//Defining preorder traversal function

void exp::preorder(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//Defining inorder traversal function

void exp::inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

//Defining postorder traversal function

void exp::postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
