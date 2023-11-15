//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    int findMaxFlow(int n,int m,vector<vector<int>> edges)
    {
        // code here
        vector<vector<int>>rgraph(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            rgraph[u-1][v-1]+=wt;
            rgraph[v-1][u-1]+=wt;
        }
        vector<int>parent(n,-1);
        int maxflow=0;
        
        while(bfs(rgraph,0,n-1,parent)){
            int mini=INT_MAX;
            for(int v=n-1;v!=0;v=parent[v]){
                int u=parent[v];
                mini=min(mini,rgraph[u][v]);
            }
            
            for(int v=n-1;v!=0;v=parent[v]){
                int u=parent[v];
                rgraph[u][v]-=mini;
                rgraph[v][u]+=mini;
            }    
              
              maxflow=maxflow+mini;
        }  
        return maxflow;
        
    }
    
    bool bfs(vector<vector<int>>&arr,int src,int dst,vector<int>&parent){
        int n = arr.size();
        vector<int>vis(n,0);
        parent[src]=-1;
        vis[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=0;v<n;v++){
                if(arr[u][v]!=0 && vis[v]==0){
                    if(v==dst){
                        parent[v]=u;
                        return true;
                    }
                    q.push(v);
                    vis[v]=1;
                    parent[v]=u;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.findMaxFlow(N, M, Edges);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends