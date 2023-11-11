//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
void dfs(int i, vector<int> adj[], int vis[]){
        vis[i]=1;
        for(auto nbr : adj[i]) 
            if(!vis[nbr]) dfs(nbr, adj , vis);
      
    } 
    int isCircle(int N, vector<string> A)
    {
        vector<int> adjList[26]; 
        int vis[26]={0};
        int l;
        for(auto s : A)
        {
            int x = s[0] - 'a';
            int y = s[s.size() - 1] - 'a';
           
            adjList[x].push_back(y);
            adjList[y].push_back(x);
             l=x;
        }
       
        dfs(l,adjList,vis);
        for(int j=0; j<26 ; j++){
            if(adjList[j].size()>0 && !vis[j]) return 0;
            if( adjList[j].size()%2==1) return 0;
        }
             
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends