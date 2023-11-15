//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int minPoints(vector<vector<int>> points, int M, int N) 
	{ 
	    vector<vector<int>> dp(M,vector<int>(N,-1000000000));
	    dp[M-1][N-1]=max(0,-points[M-1][N-1]);
	    for(int i=M-1;i>=0;i--)
	    {
	        for(int j=N-1;j>=0;j--)
	        {
	            if(i!=M-1||j!=N-1)
	            dp[i][j]=max(0,min(i+1<M?dp[i+1][j]:1000000000,j+1<N?dp[i][j+1]:1000000000)-points[i][j]);
	        }
	    }
	    return dp[0][0]+1;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends