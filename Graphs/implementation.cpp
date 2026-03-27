#include<bits/stdc++.h>
using namespace std;

// Graph class using adjacency list representation
class graph{
    public:
    // unordered_map where:
    // key = node
    // value = list of neighbors of that node
    map<int, list<int>> adj;

    // Function to add an edge in the graph
    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        // if undirected, also create edge from v to u
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    // Function to print adjacency list
    void printAdjList(){
        // loop through each node in the map
        for(auto i : adj){
            cout << i.first << " -> ";

            // print all neighbors of that node
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;   // number of vertices (not directly used but good for understanding)

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;   // number of edges

    graph g;    // create graph object

    // input edges
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        // creating an undirected graph (direction = 0)
        g.addEdge(u, v, 0);
    }

    // print adjacency list
    g.printAdjList();

    return 0;
}


//inputs
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 4 0