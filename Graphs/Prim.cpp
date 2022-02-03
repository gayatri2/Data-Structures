// #include<bits/stdc++.h>
// using namespace std;
// #define V 4

// int selectmin(int weight[], bool setMST[])
// {
//     int minimum=INT_MAX;
//     int vertex;
//     for(int i=0;i<4;i++)
//     {
//         if(setMST[i]==false && weight[i] < minimum)
//         {
//             minimum = weight[i];
//             vertex = i;

//         }
//     }
//     return vertex;
// }
// void prim(int graph [V][V])
// { 
//     //Initializations
//     int weight[4]; //track of edge weight
//     bool setMST[4];//to keep track of visited nodes
//     int parent[4]; //helps in printing the MST structure

//     for(int i=0; i<V; i++)
//         setMST[i] = false;
    
//     weight[0]=0;
//     for(int i=1; i<V; i++)
//     {
//         weight[i]=INT_MAX;
//     }
    
//     parent[0]=-1; //since source has no parent

//     //MST is V vertices, V-1 edges. So, algorithm has to be processed V-1 times. ie outer loop is the no of times all steps processed
//     for(int i=0; i<V-1; i++)    
//     {
//         int U=selectmin(weight,setMST); //select minimum from array of distances
//         setMST[U]=true; //visited

//         for(int j=0;j<V;j++) //for adjacent vertices
//         {
//             if((graph[U][j]!=0) && (weight[j] > graph[U][j]) && (setMST[j]=false)) //weight present && weight array > weight present && node is not visited
//             {
//                 weight[j]=graph[i][j];
//                 parent[j]=U;
//             }
//         }
//     }

//     //print MST
//     for(int i=1;i<4;i++)
//     {   
//         cout << "U->V:" << parent[i] << "->" << i << "weight=" << graph[parent[i]][i] << endl;
//     }


// }
// int main()
// {
//     int graph[4][4]={ 
//                         {0,3,1,0},
//                         {3,0,2,4},
//                         {1,2,0,5},
//                         {4,5,0,0}
                        
//                     };
//     cout << "Graph:" << endl;
//     for(int i = 0; i <4;i++)
//     { 
//         for(int j = 0; j < 4; j++)
//         { 
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
//     prim(graph);
   
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define V 4	//No of vertices

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

void findMST(int graph[V][V])
{
	int parent[V];		//helps in printing the MST structure
	vector<int> weight(V,INT_MAX);	////track of edge weight
	vector<bool> setMST(V,false);	////to keep track of visited nodes

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	weight[0] = 0;	//start node has value=0 to get picked 1st

   //MST is V vertices, V-1 edges. So, algorithm has to be processed V-1 times. ie outer loop is the no of times all steps processed
	
	for(int i=0;i<V-1;++i)
	{
		//Select best(minimum weight) Vertex by applying greedy method
		int U = selectMinVertex(weight,setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Go to adjacent vertices (not yet included in MST)
		for(int j=0;j<V;++j)
		{
			/* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<weight[j])
			{
				weight[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";

    int cost=0;
    for(int i=1;i<4;i++)
    {
        cost+=graph[parent[i]][i];

    }
    cout << endl;
    cout << "Cost:" << cost << endl;
}

int main()
{
	int graph[V][V] = { 
                        {0,3,1,0},
                        {3,0,2,4},
                        {1,2,0,5},
                        {4,5,0,0}
                        
                    };

	findMST(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)