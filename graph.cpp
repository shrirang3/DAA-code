#include<bits/stdc++.h>
using namespace std;
int spanningTree(int v, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        if(vis[node]==1){
            continue;
        }
        sum +=wt;
        vis[node]=1;
        for(auto it:adj[node]){
            int adjNode=it[0];
            int adjWt=it[1];
            if(!vis[adjNode]){
                pq.push({adjWt,adjNode});
            }
        }
    }
    return sum;
}
int main()
{
    
        int V, E;
        cout<<"Enter value of no.of v and e: ";
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cout<<"Enter no value of u,v and w: ";
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }    
    	
    
    cout << spanningTree(V, adj) << "\n";
    return 0;
}