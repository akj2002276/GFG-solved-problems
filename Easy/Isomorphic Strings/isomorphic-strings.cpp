//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
            if(str1.size() != str2.size()) return false;
    map<char,char> mp;
    for(int i = 0; i < str1.length(); i++) {
        if(mp.find(str1[i]) != mp.end() and mp[str1[i]] != str2[i])
                    return false;
        else
                mp[str1[i]] = str2[i];
    }
    set<int> s;
    for(auto it : mp)
        s.insert(it.second);
    return (s.size() == mp.size()) ? true : false;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends