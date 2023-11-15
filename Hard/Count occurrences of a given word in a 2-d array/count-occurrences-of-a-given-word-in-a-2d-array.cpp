//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int cnt=0;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<char>>&mat,string &target,int idx,vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j]==1)
        return ;
        
        if(idx+1==(int)(target.size())){
            if(mat[i][j]==target[idx]){
                cnt++;
                return;
            }
        }
        if(mat[i][j]!=target[idx])
        return;
        
        vis[i][j]=1;
        for(int z=0;z<4;z++){
            dfs(i+dx[z],j+dy[z],mat,target,idx+1,vis);
        }
        
        vis[i][j]=-1;
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),-1));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==target[0])
                dfs(i,j,mat,target,0,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends