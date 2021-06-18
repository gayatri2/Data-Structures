//undirected
//array that stores vertices, and then linked list to store its adjacent vertices.

#include<bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v);    //since undirected graph
    adj[v].push_back(u); 
} 
   
void printGraph(vector<int> adj[], int V) 
{ 
    for (int i = 0; i < V; i++) 
    { 
        for (int x=0; x < adj[i].size(); x++) 
           cout << adj[i][x] <<" "; 
        cout<<"\n"; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int V = 4; 
    vector<int> adj[4]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    
    printGraph(adj, V); 
    return 0; 
} 