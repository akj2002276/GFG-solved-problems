//{ Driver Code Starts
// driver code

#include<bits/stdc++.h>
using namespace std;

string LongestPalindromeSubString(string text);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<< LongestPalindromeSubString(s) << endl;
    }
    return 1;
}

// } Driver Code Ends


// return the longest palindrome substring
string LongestPalindromeSubString(string text)
{
    // Modify string
     int n = text.size();
    string ans = "@";
    for (int i = 0; i < n; i++) 
    {
        ans+= "#" + text.substr(i, 1);
    }
    ans+= "#$";
    n = ans.size();
    
    // Manacher's Algorithm
    vector<int> lps(n,0);
    int c = 0, r = 0;
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 *c - i;
        if (i<r) {
            lps[i] = min(r - i, lps[mirror]);
        }
        while (ans[i + (1 + lps[i])] == ans[i - (1 + lps[i])]) 
        {
            lps[i]++;
        }
        if (i + lps[i] > r) {
            c = i;
            r = i + lps[i];
        }
    }
     int maxi = 0, center = 0;
    for (int i = 1; i < n - 1; i++) 
    {
        if (lps[i] > maxi) 
        {
            maxi= lps[i];
            center = i;
        }
    }
    int start = (center - maxi) / 2;
    return text.substr(start, maxi);
}
