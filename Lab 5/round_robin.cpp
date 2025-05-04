//Program for round robin scheduling algorithm using circular linked list
#include "round_robin.h"
#include <iostream>
using namespace std;

int main() 
{
    int timeQuantum;
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    ProcessQueue pq(timeQuantum);
    
    int choice, time;
    while (choice != 3)
    {
        //Menu Loop
        cout<<"\n1. Insert Process";
        cout<<"\n2. Execute";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin >> choice;
        
        switch (choice) 
        {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                pq.insertProcess(time);
                break;

            case 2:
                pq.executeProcess();
                pq.displayQueue();
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } 
}
