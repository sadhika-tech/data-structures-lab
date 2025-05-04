//Program to merge two singly linked list
#include "singly_list.h"
using namespace std;

int main() 
{
    list list1, list2, list3;
    int choice, val;

    while(choice!=5)
    {
        //Printing the menu card
        cout << "\nMENU:\n";
        cout << "1. Insert into List1 (Ascending Order)\n";
        cout << "2. Insert into List2 (Ascending Order)\n";
        cout << "3. Merge List1 and List2 into List3\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to insert into List1: ";
                cin >> val;
                list1.insertas(val);
                break;

            case 2:
                cout << "Enter value to insert into List2: ";
                cin >> val;
                list2.insertas(val);
                break;

            case 3:
                list3=list();
                list3.mergelist(list1, list2);
                cout << "Lists merged successfully into List3.\n";
                break;

            case 4:
                cout<<"\nList1: ";
                list1.display();
                cout<<"List2: ";
                list2.display();
                cout<<"List3 (Merged): ";
                list3.display();
                break;

            case 5:
                cout<<"Exiting the program\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
