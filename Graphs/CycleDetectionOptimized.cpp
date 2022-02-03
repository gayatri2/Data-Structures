//Detect cycle - optimized


#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int parent;
    int rank;
};
vector<node>dsuf;

int find(int v)
{
    if(dsuf[v].parent==-1)
    {
        return v;
    }
    return dsuf[v].parent=find(dsuf[v].parent);
}
int unionop(int from_p, int to_p)
{
    //if from_p has higher rank
    if(dsuf[from_p].rank > dsuf[to_p].rank)
    {
        dsuf[to_p].parent=from_p;
    }
    //if to_p has higher rank
    else if(dsuf[to_p].rank > dsuf[from_p].rank)
    {
        dsuf[from_p].parent=to_p;
    }
    //if both have same rank
    else
    {
        dsuf[from_p].parent=to_p;
        dsuf[to_p].rank+=1;
    }
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

    for(int i = 0; i < 5; i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
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