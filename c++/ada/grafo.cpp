
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f


typedef pair<int, int> iPair;

class Graph
{
    int V;    // No. of vertices

    list< pair<int, int> > *adj;
public:

    Graph(int V);  // Constructor

    void addEdge(int u, int v, int w);

    void shortestPath(int s);
    void printPath(int parent[], int j);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph:: printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

void Graph::shortestPath(int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    int parent[V];
    parent[0]= -1;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                parent[v]= u;
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
           // cout<<i<<endl;
        }
    }
    printf("Vertex   Distance from Source \t Path\n");
    for (int i = 0; i < V; ++i)
    {
        printf("\n%d \t\t %d\n \t\t ", i, dist[i] );
        printPath(parent, i);
    }
}

int main()
{
    int V = 10000;
    Graph g(V);
}
