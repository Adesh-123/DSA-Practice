#include<bits/stdc++.h>
using namespace std;

// 1. Topological sort the graph
// 2. transpose the graph (reverse the direction of edge) x->y to x<-y
// 3. traverse the node according to topoligical order

void topologicalsort(int node,vector<vector<int>> &adj,stack<int> &st,vector<int> &vis){
    vis[node]=1;
    for(auto curr:adj[node]){
        if(vis[curr]==-1) topologicalsort(curr,adj,st,vis);
    }
    st.push(node);
}

void traversedfs(int node,vector<vector<int>> &transpose,vector<int> &vis){
    vis[node]=1;
    cout<<node<<" ";
    for(auto curr: transpose[node]){
        if(vis[curr]==-1){
            traversedfs(curr,transpose,vis);
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    stack<int> st;
    vector<int> vis(V,-1);
    for(int i=0;i<V;i++){
        if(vis[i]==-1){
            topologicalsort(i,adj,st,vis);
        }
    }

    // transpose the grpah
    vector<vector<int>> transpose(V);
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            transpose[j].push_back(i);
        }
    }
    vis=vector<int>(V,-1);
    cout<<"SCC->"<<endl;
    while(!st.empty()){
        int i=st.top();
        if(vis[i]==-1){
           traversedfs(i,transpose,vis);
           cout<<endl;
        }
        st.pop();
    }
}