//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
int nodeLevel(int V, vector<int> adj[], int X) 
{
   // code here
   queue<int>q;
   vector<int>vis(V,0);
   vis[0]=1;
   q.push(0);
   q.push(-1);
   int l=0;
   while(!q.empty()){
       int a=q.front();
       q.pop();
       if(a==X){
           return l;
       }
       else if(a==-1){
           l++;
           if(!q.empty()){
               q.push(-1);
           }
       }
       else{
           for(auto itr:adj[a]){
               if(vis[itr]==0){
                   vis[itr]=1;
                   q.push(itr);
               }
           }
       }
   }
   return -1;
}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends