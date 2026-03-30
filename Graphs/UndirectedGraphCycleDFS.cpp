#include<bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected) return true;
        }
        else if(neighbour != parent){
            //cycle present
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges){
    //create adjacency list
    unordered_map<int, vector<int>> adj;
    for(int i=0; i<(int)edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnectd components in graphs
    unordered_map<int, bool> visited;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V;
    cout << "Enter the vertices : " << endl;
    cin >> V;

    int E;
    cout << "Enter the edges : " << endl;
    cin >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if(isCycle(V, edges)){
        cout << "Cycle is present in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }



    return 0;
}


//output ->
// Enter the vertices : 
// 4
// Enter the edges : 
// 4
// Enter edges (u v):
// 0 1
// 0 2
// 1 2
// 2 3
// Cycle is present in the graph.