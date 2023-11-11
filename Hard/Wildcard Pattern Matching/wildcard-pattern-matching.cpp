//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
bool helper(int n, int m, string &pattern, string &str, vector<vector<int>> &dp)
    {
        if(n == 0 && m == 0) return true;
        if(n < 0 || m < 0) return false;
        if(dp[n][m] != -1) return dp[n][m];
        if(pattern[n-1] == str[m-1] || pattern[n-1] == '?') return dp[n][m] = helper(n-1, m-1, pattern, str, dp);
        else if(pattern[n-1] == '*')  return dp[n][m] =  helper(n, m-1, pattern, str, dp) || helper(n-1, m, pattern, str, dp);
    }
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n, m, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends