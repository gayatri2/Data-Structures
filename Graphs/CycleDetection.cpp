//Detect cycle

#include <bits/stdc++.h>
using namespace std;

int parent[4];

int find(int v)
{
    if(parent[v]==-1)
    {
        return v;
    }
    return find(parent[v]);
} 
int unionop(int from_p, int to_p)
{
    //find root
    from_p=find(from_p);
    to_p=find(to_p);
    //then point from_p's root to to_p's root
    parent[from_p] = to_p;
}
bool isCycle(vector<pair<int,int>>&edge_list)
{
    for(auto p: edge_list)
    {
        int from_p = find(p.first); //find absolute parent (root)
        int to_p = find(p.second);

        if(from_p == to_p) //same parent, so cycle created
        {
            return true;
        }
        //if roots are different, so union operation
        unionop(from_p, to_p); //of two sets
    }
    return false;
}
int main()
{
    int v,e;
    cout << "Enter the number of edges and vertices:"<<endl;
    cin >> v >> e;

    for(int i = 0; i < 4; i++)
    {
        parent[i]=-1;
    }
    vector<pair<int,int>>edge_list;  //will contain source, destination
    for(int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        edge_list.push_back({from,to});
    }

    if(isCycle(edge_list))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    
    
    return 0;
}