//Given a connected undirected graph containing V vertices represented by a 2-d adjacency list 
//adj[][], where each adj[i] represents the list of vertices connected to vertex i. 
//Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from 
//left to right as per the given adjacency list, and return a list containing the DFS traversal 
//of the graph.

#include<bits/stdc++.h>
using namespace std;

// DFS function to traverse the graph
void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, 
        vector<int>& component){
    
    // Add current node to the traversal result
    component.push_back(node);

    // Mark the node as visited
    visited[node] = true;
    
    // Traverse all adjacent nodes
    for(auto i : adj[node]){
        // If the adjacent node is not visited, call DFS recursively
        if(!visited[i]){
            dfs(i, visited, adj, component);
        }
    }
}

// Function to perform DFS for the entire graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges){
    
    // Step 1: Create adjacency list from given edges
    unordered_map<int, list<int>> adj;

    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // Since graph is undirected, add both directions
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // This will store DFS traversal for all components
    vector<vector<int>> ans;

    // Track visited nodes
    unordered_map<int, bool> visited;

    // Step 2: Traverse all vertices (important for disconnected graph)
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;

            // Call DFS for each unvisited node
            dfs(i, visited, adj, component);

            // Store the component traversal
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){
    int V;
    cout << "Enter the number of vertices : " << endl;
    cin >> V;  

    int E;
    cout << "Enter the number of edges : " << endl;
    cin >> E;   

    cout << "Enter the edges : " << endl;

    // Store edges as pairs (u, v)
    vector<vector<int>> edges(E, vector<int>(2));

    for(int i=0; i<E; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    // Call DFS traversal function
    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    cout << "DFS traversal for the given graph is : " << endl;

    // Print all components
    for(auto component : result){
        for(int node : component){
            cout << node << " ";
        }
    }
    cout << endl;

    return 0;
}


// output ->

// Enter the number of vertices : 
// 5
// Enter the number of edges : 
// 5
// Enter the edges : 
// 0 2
// 2 1
// 1 3
// 3 4
// 4 2
// DFS traversal for the given graph is : 
// 0 2 1 3 4