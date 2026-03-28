//Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list 
//adj[][], where each adj[i] represents the list of vertices connected to vertex i. 
//Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from 
//left to right according to the given adjacency list, and return a list containing the BFS 
//traversal of the graph

#include<bits/stdc++.h>
using namespace std;

// Function to create adjacency list from given edges
vector<vector<int>> createAdjList(int V, int E){
    vector<vector<int>> adj(V);   // adjacency list with V vertices

    // Taking E edges as input
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;   // input edge between u and v

        adj[u].push_back(v);   // add v to u's list
        adj[v].push_back(u);   // add u to v's list (undirected graph)
    }
    return adj;   // return constructed adjacency list
}

// Function to perform BFS traversal
vector<int> bfs(vector<vector<int>> &adj){
    int V = adj.size();   // number of vertices

    queue<int> q;                 // queue for BFS
    vector<bool> visited(V, false); // visited array to track visited nodes
    vector<int> bfs;              // store BFS traversal result

    // start from node 0
    q.push(0);           // push starting node into queue
    visited[0] = true;   // mark it as visited

    // BFS traversal loop
    while(!q.empty()){
        int node = q.front(); // get front node
        q.pop();              // remove it from queue

        bfs.push_back(node);  // add node to result

        // traverse all neighbours of current node
        for(auto neighbour : adj[node]){
            // if neighbour not visited
            if(!visited[neighbour]){
                visited[neighbour] = true; // mark visited
                q.push(neighbour);         // push into queue
            }
        }
    }
    return bfs;   // return BFS traversal
}

int main(){
    int V;
    cout << "Enter the number of vertices : " << endl;
    cin >> V;   // input number of vertices

    int E;
    cout << "Enter the number of edges : " << endl;
    cin >> E;   // input number of edges

    cout << "Enter the edges : " << endl;

    // create adjacency list using input edges
    vector<vector<int>> adj = createAdjList(V, E);

    // perform BFS traversal
    vector<int> result = bfs(adj);

    cout << "BFS traversal for the given graph is : " << endl;

    // print BFS result
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}



// output ->

// Enter the number of vertices : 
// 5
// Enter the number of edges : 
// 6
// Enter the edges : 
// 0 1
// 0 2
// 1 3
// 2 4
// 3 4
// 1 4
// BFS traversal for the given graph is : 
// 0 1 2 3 4