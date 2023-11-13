//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int n,vector<vector<int>>&cost,int mask){
    if(mask==0)return cost[i][0];// cost fromt the last city visited to the 
    // start city i.e city 0
    
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=1e9+7;
    for(int j=0;j<n;j++){
        if(mask&(1<<j)){
            ans=min(ans,cost[i][j]+solve(j,n,cost,mask^(1<<j)));
            //marking the jth city visited while going from city i to city j
        }
    }
    return dp[i][mask]=ans;
}
int total_cost(vector<vector<int>>cost){
    int n=cost.size();
    if(n==1)return 0;
    
    int mask=(1<<n)-1;
    dp=vector<vector<int>>(n+1,vector<int>(mask+1,-1));
    mask^=(1<<0);// marking the city 0 visited by unsetting the 0th bit
    return solve(0,n,cost,mask);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends