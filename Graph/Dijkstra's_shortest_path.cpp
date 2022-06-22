#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E,S;
    cin>>V>>E>>S;
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0;i<E;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(V,INT_MAX);
    dis[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        auto node=pq.top().second;
        pq.pop();
        for(auto curr:adj[node]){
            int child=curr.first;
            int w=curr.second;
            if(dis[child]>w+dis[node]){
                dis[child]=w+dis[node];
                pq.push({dis[child],child});
            }
        }
    }
    for(int i=0;i<V;i++){
      cout<<dis[i]<<" ";
    }
}