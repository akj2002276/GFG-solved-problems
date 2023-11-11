//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>&matrix , int N , int M , int row , int col)
    {
        if(row < 0 || row >= N || col < 0 || col >= M || matrix[row][col] == 0) return;
        matrix[row][col] = 0;
        dfs(matrix , N , M , row-1 , col);
        dfs(matrix , N , M , row + 1 , col);
        dfs(matrix , N , M , row , col - 1);
        dfs(matrix , N , M , row , col + 1);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int row = 0;row < N; row++)
        {
            if(matrix[row][0] == 1) dfs(matrix , N , M , row , 0);
            if(matrix[row][M-1] == 1) dfs(matrix , N , M , row , M-1);
        }
        for(int col = 0; col < M; col++)
        {
            if(matrix[0][col] == 1) dfs(matrix , N , M , 0 , col);
            if(matrix[N-1][col] == 1) dfs(matrix , N , M , N-1 , col);
        }
        
        int count = 0;
        for(int row = 0;row < N; row++)
        {
            for(int col = 0;col < M;col++)
            {
                if(matrix[row][col] == 1)
                {
                    count++;
                    dfs(matrix,N,M,row,col);
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends