//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
#define ll long long
#include<bits/stdc++.h>


    int matrixMultiplication(int n, int arr[]){
        int dp[200][200];
        memset(dp, 0, sizeof dp);
        for(int i=1;i<n;i++){
            int r = 0, c = i;
            
            while(c<n){
                int val = INT_MAX;
                for(int pivot = r; pivot < c; pivot++){
                    val = min(val, dp[r][pivot] + dp[pivot+1][c] + (arr[r] * arr[pivot+1] * arr[c+1]));
                }
                dp[r][c] = val;
                
                r++, c++;
            }
        }
        return dp[0][n-2];
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends