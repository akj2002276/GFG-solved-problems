//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU{
public:
    vector<int>size,parent;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUlParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUlParent(parent[node]);
    }
    void UbS(int u,int v){
        int up_u = findUlParent(u);
        int up_v = findUlParent(v);
        if(up_u==up_v)return;
        if(size[up_u]>size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
    }
};

class Solution {
  public:
  
  
   vector<int>dx = {0,0,1,-1};  // Finding the adjacnet row value
  vector<int>dy = {1,-1,0,0}; // Finding the adjacent col value
  void makeUnion(DSU &ds,int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int n,int m){
      vis[i][j]=1;
      queue<pair<int,int>>q;
      q.push({i,j});
      
    //   Using BFS to merge the connected '1's
    
      while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for(int k=0;k<4;k++){
              int nx = x+dx[k];
              int ny = y+dy[k];
              if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                  vis[nx][ny]=1;
                  int kx = m*x+y;
                  int kz = m*nx+ny;
                  ds.UbS(kx,kz);
                  q.push({nx,ny});
              }
          }
      }
  }
  
  int findIsland(int i,int j,vector<vector<int>>&grid,DSU &ds,int n,int m){
      int size=1; // Initially it is one if we filp '0' to '1'
      unordered_set<int>st; // Adjacent '1's can be of the same parent, so inserting them into a set
      for(int k=0;k<4;k++){
          int nx = i+dx[k];
          int ny = j+dy[k];
          if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
              int node = m*nx+ny;
              int par = ds.findUlParent(node);
              st.insert(par);
          }
      }
      for(auto it:st){
          size+=ds.size[it];
      }
      return size;
  }
  
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        DSU ds(n*m); // Creating the Object of DSU Class of size(n*m) for a linear array
        
        vector<vector<int>>vis(n,vector<int>(m,0)); // For keeping track of islands we make
        
        
        // First, We are going to create islands with the '1's given in the grid
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    makeUnion(ds,i,j,grid,vis,n,m); //Uniting the adjacent '1's 
                }
            }
        }
        
        
        int cnt=0;
        // Find the size of largest Island
        for(auto it:ds.size){
            cnt=max(cnt,it);
        }
        
        // For every '0' we find how much big island it will make with the adjacent '1's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    cnt = max(cnt,findIsland(i,j,grid,ds,n,m)); // Finding the largest Island it can create
                }
            }
        }
        
        // Return the largest Island size
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends