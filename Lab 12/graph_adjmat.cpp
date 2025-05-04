//Program on graph ADT adjacency matrix
#include <iostream>
#include <list>
using namespace std;

class GraphList 
{
    int V;
    list<int>* adj;

public:
    GraphList(int v)
    {
        V = v;
        adj = new list<int>[V];
    }
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    bool searchEdge(int u, int v);
    void display();
};

int main() 
{
    int v, choice, u, w;
    cout << "Enter number of vertices: ";
    cin >> v;
    GraphList g(v);

    do 
    {
        //Printing Menu Loop
        cout<<"\n1.To insert an edge\n";
        cout<<"2.To delete an edge\n";
        cout<<"3.To search an edge\n";
        cout<<"4.To display the graph\n";
        cout<<"5.To exit the program\n";
        cout<<"Enter choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                g.insertEdge(u, w);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                g.deleteEdge(u, w);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> w;
                cout << (g.searchEdge(u, w) ? "Exists" : "Doesn't exist") << endl;
                break;
            case 4:
                g.display();
                break;
        }
    } while (choice != 5);

    return 0;
}

//Definition to insert edge
void GraphList::insertEdge(int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Definition to delete edge
void GraphList::deleteEdge(int u, int v) 
{
    adj[u].remove(v);
    adj[v].remove(u);
}

//Definition to search edge
bool GraphList::searchEdge(int u, int v) 
{
    for (int x : adj[u])
        if (x == v) return true;
    return false;
}

//Definition to display graph
void GraphList::display() 
{
    for (int i = 0; i < V; ++i) 
    {
        cout << i << ": ";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}