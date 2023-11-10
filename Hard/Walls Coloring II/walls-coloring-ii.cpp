//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
int minCost(vector<vector<int>> &costs) {
        
        int n=costs.size();
        int k=costs[0].size();
        
        if(n>1 && k==1) return -1;
        
        priority_queue<pair<int,int>>q;
        
        vector<vector<int>>dp(n,vector<int>(k,-1));
        
        for(int i=0;i<k;i++)
        {
            dp[0][i]=costs[0][i];
            
            if(q.size()<=1)
                {
                    q.push({dp[0][i],i});
                    
                }
                else
                {
                   if(dp[0][i]<q.top().first)
                   {
                       q.pop();
                       q.push({dp[0][i],i});
                   }
                }
        }
        
        for(int i=1;i<costs.size();i++)
        {
           
            auto second=q.top();
            q.pop();
            auto first=q.top();
            q.pop();
            
            for(int j=0;j<k;j++)
            {
                
            
                if(first.second!=j)
                {
                    dp[i][j]=costs[i][j]+first.first;
                }
                else
                {
                   dp[i][j]=costs[i][j]+second.first;
                }
                
                
               if(q.size()<=1)
                {
                    q.push({dp[i][j],j});
                    
                }
                else
                {
                   if(dp[i][j]<q.top().first)
                   {
                       q.pop();
                       q.push({dp[i][j],j});
                   }
                }
            
           
        }
        
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<k;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends