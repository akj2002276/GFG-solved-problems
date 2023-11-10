//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dfs(vector<int>adj[],int V,int node,int rank,vector<int> &ranks,vector<vector<int>> &ans){
        if(ranks[node]!=-2) return ranks[node];
        
        int low=rank;
        ranks[node]=rank;
        for(auto nei:adj[node]){
            if(ranks[nei]==rank-1 || ranks[nei]==V) continue;
            int neirank=dfs(adj,V,nei,rank+1,ranks,ans);
            low=min(low,neirank);
            if(neirank>rank) ans.push_back({min(node,nei),max(node,nei)});
        }
        ranks[node]=V;
        return low;
    }
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int>>ans;
	    vector<int>ranks(V,-2);
	   // memset(ranks,-2,V);
	    dfs(adj,V,0,0,ranks,ans);
	   // for(auto i:ranks) cout<<i<<" ";
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends