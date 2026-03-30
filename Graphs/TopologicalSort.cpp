#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
    visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour, visited, s, adj); 
    }
    s.push(node);
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<(int)edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
            
        adj[u].push_back(v);   //directed
    }
        
    //call dfs topological sort util function for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
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

    vector<int> result = topoSort(V, edges);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}



// output->
// Enter the vertices : 
// 4
// Enter the edges : 
// 3
// Enter edges (u v) : 
// 2 0
// 1 0
// 3 0
// 3 2 1 0 