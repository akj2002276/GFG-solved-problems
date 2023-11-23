//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
    
public:
     int mod = 1e9+7;
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<long long>> temp(n,vector<long long> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                temp[i][j]=1;
                else
                {
                    temp[i][j] = temp[i-1][j]%mod + temp[i-1][j-1]%mod;
                }
            }
        }
        vector<long long> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(temp[n-1][i]%mod);
        }
        return ans;
    }
};

//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends