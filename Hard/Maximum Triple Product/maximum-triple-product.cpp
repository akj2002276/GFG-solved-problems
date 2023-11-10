//{ Driver Code Starts
//Initial Template for C++#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
long long int maxProductSum(int N, int arr[])
    {
        // code here
        vector<long long>nums;
        nums.push_back(1);
        for(int i=0; i<N; i++){
            nums.push_back(arr[i]);
        }
        nums.push_back(1);
        
        vector<vector<long long>>dp(N+2, vector<long long>(N+2, 0));
        for(int i=N; i>=1; i--){
            for(int j=1; j<=N; j++){
                if(i>j) continue;
                long long maxi=INT_MIN;
                for(int ind=i; ind<=j; ind++){
                    long long cost=nums[i-1]*nums[ind]*nums[j+1];
                    cost+=dp[i][ind-1];
                    cost+=dp[ind+1][j];
                    maxi=max(maxi, cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][N];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.maxProductSum(N,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends