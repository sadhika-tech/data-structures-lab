//Program on graph ADT to implement Prim, Dijkstra, Kruskal algorithm
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int MAX = 100;

class Edge 
{
    public:
    int src, dest, weight;
};

class Graph 
{

    private:
        int V;
        int adj[MAX][MAX];
        Edge edgeList[MAX * MAX];
        int edgeCount;

    public:
        Graph(int vertices);
        void addEdge(int u, int v, int weight);
        void displayGraph();
        void primMST();
        void kruskalMST();
        void dijkstra(int src);

    private:
        int findSet(int parent[], int i);
        void unionSets(int parent[], int rank[], int x, int y);

};

int main() 
{
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    if (V <= 0 || V > MAX) 
    {
        cout << "Invalid number of vertices.\n";
        return 1;
    }
    Graph g(V);
    do {
        //Printing menu loop
        cout << "\nMenu Loop\n";
        cout << "1. To add edge\n";
        cout << "2. To display graph\n";
        cout << "3. Prim's MST\n";
        cout << "4. Kruskal's MST\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "6. To exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: 
                int u, v, w;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            
            case 2:
                g.displayGraph();
                break;

            case 3:
                g.primMST();
                break;

            case 4:
                g.kruskalMST();
                break;

            case 5:
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                g.dijkstra(src);
                break;

            case 6:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid choice.\n";

            }

    } while (choice != 6);

 

    return 0;

}

//Definition to construct graph 
Graph::Graph(int vertices) 
{
    V = vertices;
    edgeCount = 0;
    memset(adj, 0, sizeof(adj));
}

//Definition to add edge
void Graph::addEdge(int u, int v, int weight) 
{
    if(u<0||v<0||u>=V||v>=V||weight<=0) 
    {
        cout<<"Invalid edge.\n";
        return;
    }
    adj[u][v] = weight;
    adj[v][u] = weight;
    edgeList[edgeCount].src = u;
    edgeList[edgeCount].dest = v;
    edgeList[edgeCount].weight = weight;
    edgeCount++;
}

//Definition to display graph
void Graph::displayGraph() 
{
    cout<<"\nAdjacency Matrix:\n";
    for(int i=0;i<V;i++) 
    {
        for(int j=0;j<V;j++) 
        {
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//Definition to prim MST
void Graph::primMST() 
{
    int key[MAX], parent[MAX];
    bool inMST[MAX];
    for(int i=0;i<V;i++) 
    {
        key[i] = INT_MAX;
        inMST[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count=0;count<V-1;count++) 
    {
        int min = INT_MAX, u = -1;
        for(int v=0;v<V;v++)
            if(!inMST[v]&&key[v]<min) 
            {
                min = key[v];
                u = v;
            }
        inMST[u] = true;
        for(int v=0;v<V;v++) 
        {
            if(adj[u][v]&&!inMST[v]&&adj[u][v]<key[v]) 
            {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    cout<<"\nPrim's MST:\nEdge\tWeight\n";
    for(int i=1;i<V;i++)
        cout<<parent[i]<<" - "<<i<<"\t"<<adj[i][parent[i]]<<"\n";
}

//Definition to find set

int Graph::findSet(int parent[], int i) 
{
    if(parent[i]!=i)
    {
        parent[i] = findSet(parent, parent[i]);
    }
    return parent[i];
}

//Definition to get union set
void Graph::unionSets(int parent[], int rank[], int x, int y) 
{
    int xroot = findSet(parent, x);
    int yroot = findSet(parent, y);
    if(rank[xroot]<rank[yroot])
        parent[xroot] = yroot;
    else if(rank[xroot]>rank[yroot])
        parent[yroot] = xroot;
    else 
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

//Definition for kruskal MST
void Graph::kruskalMST() 
{
    Edge result[MAX];
    int e = 0;
    int parent[MAX], rank[MAX];
    for(int i=0;i<V;i++) 
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i=0;i<edgeCount-1;i++) 
    {
        for(int j=0;j<edgeCount-i-1;j++) 
        {
            if(edgeList[j].weight>edgeList[j+1].weight) 
            {
                Edge temp = edgeList[j];
                edgeList[j] = edgeList[j+1];
                edgeList[j+1] = temp;
            }
        }
    }
    for(int i=0;i<edgeCount&&e<V-1;i++) 
    {
        Edge next = edgeList[i];
        int x = findSet(parent, next.src);
        int y = findSet(parent, next.dest);
        if(x!=y) 
        {
            result[e++] = next;
            unionSets(parent, rank, x, y);
        }
    }
    cout<<"\nKruskal's MST:\nEdge\tWeight\n";
    for(int i=0;i<e;i++)
        cout<<result[i].src<<" - "<<result[i].dest<<"\t"<<result[i].weight<<"\n";
}

//Definition for dijkstra algorithm
void Graph::dijkstra(int src) 
{
    if(src<0||src>=V) 
    {
        cout<<"Invalid source.\n";
        return;
    }
    int dist[MAX];
    bool visited[MAX];
    for(int i=0;i<V;i++) 
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for(int count=0;count<V-1;count++) 
    {
        int u = -1, min = INT_MAX;
        for(int i=0;i<V;i++) {
            if(!visited[i]&&dist[i]<min) 
            {
                min = dist[i];
                u = i;
            }
        }
        if(u==-1) break;
        visited[u] = true;
        for(int v=0;v<V;v++) 
        {
            if(adj[u][v]&&!visited[v]&&dist[u]+adj[u][v]<dist[v]) 
            {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    cout<<"\nDijkstra's shortest paths from node "<<src<<":\n";
    for(int i=0;i<V;i++) {
        if(dist[i]==INT_MAX)
            cout<<"To "<<i<<": Unreachable\n";
        else
            cout<<"To "<<i<<": "<<dist[i]<<"\n";
    }
}