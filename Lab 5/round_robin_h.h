//Header file for Round Robin
#define PROCESSQUEUE_H

#include <iostream>
using namespace std;

class ProcessQueue 
{
    private:
        struct Node 
        {
            int time;
            Node* next;
        };
        Node* head;
        int timeQuantum;

    public:
        ProcessQueue(int tq) 
        {
            head = NULL;
            timeQuantum = tq;
        };
        void insertProcess(int);
        void executeProcess();
        void displayQueue();
        
};
//Defining insert process function
void ProcessQueue::insertProcess(int time) 
{
    Node* newNode = new Node();
    newNode->time = time;
    
    if (head==NULL) 
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; 
    }
    cout << "Process with time " << time << " inserted.\n";
}
//Defining execute process function
void ProcessQueue::executeProcess()
{
    if (head==NULL) 
    {
        cout << "No processes in the queue.\n";
        return;
    }
    
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    int remainingTime = temp->time - timeQuantum;
    cout << "Executing process with time " << temp->time;
    cout<< " (Remaining: " << max(remainingTime, 0) << ")\n";
    if (head == head->next) {
        delete head;
        head = NULL;
    } 
    else 
    {
        prev->next = head->next;
        delete head;
        head = prev->next;
    }
    if (remainingTime > 0) 
    {
        insertProcess(remainingTime);
    }
}



//Defining display queue function
void ProcessQueue::displayQueue()
{
    if (head==NULL) 
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = head->next;
    do 
    {
        cout << temp->time << " ";
        temp = temp->next;
    } 
    while (temp != head->next);
    cout << "\n";
}