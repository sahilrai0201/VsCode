#include<bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj){
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
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
            bool ans = isCyclicBFS(i, visited, adj);
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