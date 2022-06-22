#include <bits/stdc++.h>
using namespace std;

// DFS TRAVERSAL FUNCTION
bool dfscycledetect(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto curr : adj[node])
    {
        if (vis[curr] == 0)
        {
            if (dfscycledetect(curr, adj, vis, dfsvis))
                return true;
        }
        else if(dfsvis[curr]==1)  return true;
    }
    dfsvis[node] = 0;
    return false;
}

int main()
{

    int V, E; // V ->no of vertex,E->no of edge;
    cin >> V >> E;

    // cout<<"Hi"<<endl;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int x, y; // x->y
        cin >> x >> y;
        adj[x].push_back(y); // directed graph
    }

    vector<int> vis(V, 0);    // visited array
    vector<int> dfsvis(V, 0); // visited array for every call
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (dfscycledetect(i, adj, vis, dfsvis))
            {
                cout << "CYCLE IS PRESENT" << endl;
                return 0;
            }
        }
    }
    cout << "CYCLE IS NOT PRESENT" << endl;
    return 0;
}