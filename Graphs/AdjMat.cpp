//undirected adjacency matrix
//1. add edge 2.remove edge 3.count the number of edges

#include <iostream>
using namespace std;

class Graph {
  private:
  bool** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void print() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
  void count(){ //count the no of edges in undirected; 
   // The count of edge is always even because in
    // undirected graph every edge is connected
    // twice between two vertices
  int sum=0;
    for(int i=0;i<numVertices;i++)
    {
      for(int j=0; j<numVertices;j++)
      {
        if(adjMatrix[i][j]==1)
        {
          sum+=1;
        }
      }
    }
  cout << "Number of edges:" << sum/2 << endl; 

  }
};

int main() {
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.count();
  g.print();
}

