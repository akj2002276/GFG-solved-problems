//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{

  public:

    int cnt=0;

    int countVertex(int N, vector<vector<int>>edges){

        // code here

        vector<int>adj[N];

        for(int i=0;i<edges.size();i++){

            int a=edges[i][0];

            int b=edges[i][1];

            adj[a-1].push_back(b-1);

            adj[b-1].push_back(a-1);

        }

        bool x=dfs(adj,0,-1,N);

        return cnt;

    }

    bool dfs(vector<int>adj[],int node,int par,int N){

        bool check=false;

        for(int i=0;i<adj[node].size();i++){

            if(adj[node][i]!=par){

                bool y=dfs(adj,adj[node][i],node,N);

                if(y==false){

                    check=true;

                }

            }

        }

        if(check) cnt++;

        return check;

    }

};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends