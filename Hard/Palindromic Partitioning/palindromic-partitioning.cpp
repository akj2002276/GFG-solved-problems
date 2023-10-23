//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(int n, string s){
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--){
            int ans = INT_MAX;
            int count;
            
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s)){
                    count = 1 + dp[j+1];
                    ans = min(ans, count);
                }
            }
            dp[i] = ans;
        }
        
        return dp[0];
    }

    int palindromicPartition(string str)
    {
        int n = str.length();
        return solve(n, str)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends