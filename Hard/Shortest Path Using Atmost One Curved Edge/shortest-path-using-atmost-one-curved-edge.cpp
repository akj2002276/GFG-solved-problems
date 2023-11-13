//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dyjkstra(int source,  vector<vector<pair<int,pair<int,int>>>> &adj, vector<vector<long long int>> &dis){
        priority_queue<pair<long long int,pair<int,int>>, vector<pair<long long int,pair<int,int>>>, greater<pair<long long int,pair<int,int>>>> q;
        q.push({0,{source,0}});
        dis[source][0]=0;
        while(!q.empty()){
            auto temp=q.top();
            int par = temp.second.first;
            int flag = temp.second.second;
            q.pop();
            for(auto node: adj[par]){
                int child=node.first;
                int st_wt=node.second.first;
                int cu_wt=node.second.second;
                
                if(flag==1){
                    if(dis[par][1] + st_wt < dis[child][1]){
                        dis[child][1] = dis[par][1] + st_wt;
                        q.push({dis[child][1],{child,1}});
                    }
                }
                else{
                    if(flag==0){
                        if(dis[par][0] + st_wt < dis[child][0]){
                            dis[child][0] = dis[par][0] + st_wt;
                            q.push({dis[child][0],{child,0}});
                        }
                        if(dis[par][0] + cu_wt < dis[child][1]){
                            dis[child][1] = dis[par][0] + cu_wt;
                            q.push({dis[child][1],{child,1}});
                        }
                    }
                }
            }
        }
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<vector<long long int>> dis(n+1, vector<long long int>(2,LONG_MAX));
        vector<vector<pair<int,pair<int,int>>>> adj(n+1);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1],{edge[2],edge[3]}});
            adj[edge[1]].push_back({edge[0],{edge[2],edge[3]}});
        }
        dyjkstra(a,adj,dis);
        return min(dis[b][0],dis[b][1]);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends