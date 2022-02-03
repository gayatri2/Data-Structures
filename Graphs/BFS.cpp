//Given undirected graph and source vertex ‘s’.

#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s) 
{ 
	bool visited[5]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; //make visited of every vertex as false

	queue<int>  q;
	
	visited[s] = true;  //source vertex is like root
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		cout << u << " "; 
		 
		for(int v:adj[u]){ //traversing the list at that vertex index. u is the element at the queue front
		    if(visited[v]==false){
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 

void addEdge(vector<int> adj[], int u, int v){  //undirected
    adj[u].push_back(v);    
    adj[v].push_back(u);
}

int main() 
{ 
	int V=5;
	vector<int> adj[5];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS(adj,V,0); //BFS(adj, no of vertices, source vertex)

	return 0; 
} 
