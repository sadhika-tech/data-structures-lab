//Program to check if the paranthesis is balanced
#include<iostream>
#include "stack.h"

int checkbalance(string);

int main(){
    string in;
    int choice;
    int check;
    do{
        //Printing Menu Card
        cout<<"\n\nMenu : \n1. Check Balance\n2. Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"\n\n1. Check Balance of string : ";
            cout<<"\nEnter the string : ";
            cin>>in;
            check=checkbalance(in);
            if(check==1)
            cout<<"\nThe string is balanced\n";
            else
            cout<<"\nThe string is not balanced\n";
            break;

            case 2:
            cout<<"\n\nTerminating program... ";
            exit(0);
            break;

            default:
            cout<<"\n\nInvalid case entered!!";
            break;
        }
    }while(choice!=2);
}

//Defining parantheses are balanced function
int checkbalance(string in)
{
    stack s;

    for(char c : in)
    {
        if(c=='(')
        s.push(c);
        else if(c==')')
        {
            if(s.isempty())
            {
                return -1;
            }
           s.pop(); 
        }
        else
        continue;
    }
    if(s.isempty())
    return 1;
    else
    return -1;
}