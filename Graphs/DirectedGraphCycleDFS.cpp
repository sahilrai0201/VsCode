#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, 
    unordered_map<int, list<int>> &adj){

    visited[node] = true;    
    dfsVisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
            if(cycleDetected)
                return true;
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges){
    //create adjacency list
    unordered_map<int, list<int>> adj;  
    for(int i=0; i<(int)edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);    //directed graph
    }

    //dfs call for all components
    unordered_map<int, bool> visited;  
    unordered_map<int, bool> dfsVisited;  
    for(int i=1; i<=V; i++){
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if(cycleFound)
                return true;
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

    cout << "Enter edges (u v) : " << endl;
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if(isCyclic(V, edges)){
        cout << "Cycle is present in the graph." << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }


    return 0;
}



// output -> 
// Enter the vertices : 
// 4
// Enter the edges : 
// 4
// Enter edges (u v) : 
// 0 1
// 1 2
// 2 0
// 2 3
// Cycle is present in the graph.