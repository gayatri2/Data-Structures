#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices
int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}
void dijkstra(int graph[V][V])
{
	int parent[V];		//helps in printing the structure
	vector<int> weight(V,INT_MAX);	////track of edge weight
	vector<bool> setMST(V,false);	////to keep track of visited nodes

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	weight[0] = 0;	//start node has value=0 to get picked 1st

   //V vertices, V-1 edges. So, algorithm has to be processed V-1 times. ie outer loop is the no of times all steps processed
	
	for(int i=0;i<V-1;++i)
	{
		//Select best(minimum weight) Vertex by applying greedy method
		int U = selectMinVertex(weight,setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Go to adjacent vertices (not yet included in MST)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
            
			if(graph[U][j]!=0 && setMST[j]==false && weight[U]!=INT_MAX && (weight[U]+graph[U][j]<weight[j]))
			{
				weight[j] = weight[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";

   cout<< "Minimum cost to reach the vertices from source vertex:"<<endl;
   for(int i=0;i<V;++i)
   {
       cout << weight[i] << " ";
   }
}

int main()
{
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
	dijkstra(graph);	
	return 0;
}
