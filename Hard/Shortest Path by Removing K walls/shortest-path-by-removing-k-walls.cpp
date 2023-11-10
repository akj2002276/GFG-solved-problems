//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n+1,vector<int>(m+1,-1));
        q.push({{0,0},k});
        vis[0][0]=k;
        int ans=INT_MAX;
        int res=0;
        
        while(q.empty()==false)
        {
           int size=q.size();
           
            while(size)
           {
               auto x=q.front();
               q.pop();
               
               if(x.first.first==n-1 && x.first.second==m-1)
               {
                   return res;
               }
               
               int rem=x.second;
               
               vector<int>a{0,-1,0,1};
               vector<int>b{-1,0,1,0};
               
               for(int k=0;k<4;k++)
               {
                   int nx=x.first.first+a[k];
                   int ny=x.first.second+b[k];
                   
                   if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]<rem)
                   {
                       
                       if(mat[nx][ny]==0)
                       {
                           q.push({{nx,ny},rem});
                           vis[nx][ny]=rem;
                       }
                       else if(mat[nx][ny]==1 && rem>0)
                       {
                           q.push({{nx,ny},rem-1});
                           vis[nx][ny]=rem-1;
                       }
                       
                       
                   }
                   
                   
                   
               }
               
               
               
               size--;
           }
           
           res++;
            
            
        }
        
        
        return -1;
        
    }
        
                                            
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends