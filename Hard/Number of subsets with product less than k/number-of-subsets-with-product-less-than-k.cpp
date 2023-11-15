//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int solve(int i, int n, int k, int arr[]){
        if(i >= n){
            if(k > 0){
                return 1;
            }
            return 0;
        }
        
        int take = 0;
        if(arr[i] <= k){
            take = solve(i+1, n, k/arr[i], arr);
        }
        
        int skip = solve(i+1, n, k, arr);
        
        return skip+take;
    }
  
    int numOfSubsets(int arr[], int n, int k) {
        return solve(0, n, k, arr)-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends