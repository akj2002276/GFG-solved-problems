//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n,vector<int>(n,1000000000));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=freq[i];
        }
        for(int len=1;len<n;len++)
        {
            for(int i=0;i+len<n;i++)
            {
                int sum=0;
                for(int k=i;k<=len+i;k++)
                {
                    sum+=freq[k];
                   
                }
               
                dp[i][i+len]=sum+dp[i+1][i+len];
                for(int j=i+1;j<i+len;j++)
                {
                    dp[i][i+len]=min(dp[i][i+len],dp[i][j-1]+dp[j+1][i+len]+sum);
                }
                  dp[i][i+len]=min(dp[i][i+len],dp[i][i+len-1]+sum);
                
            }
            
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends