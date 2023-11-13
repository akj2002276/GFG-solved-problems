//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    
    unordered_map<string, bool> mp;
    
    Solution(){
        mp.clear();
    }
    bool isScramble(string S1, string S2){
        //code here
        
        if(S1.compare(S2)==0)return true;
        if(S1.length()<=1)return false;
        int n =S1.length();
        
        string key = S1+""+S2; // Prepare the key
        
        
        if(mp.find(key)!=mp.end())return mp[key]; // Search if a values already exists in the map
        bool scrambled =false;
        
        for(int i=1;i<n;i++){
            
            // SWAP CASE
            bool cond1 = (isScramble(S1.substr(0,i), S2.substr(n-i,i))==true ) && 
            (isScramble(S1.substr(i,n-i), S2.substr(0,n-i))==true );
            // NON SWAP CASE
            bool cond2 = (isScramble(S1.substr(0,i), S2.substr(0,i))==true ) && 
            (isScramble(S1.substr(i,n-i), S2.substr(i,n-i))==true );
            
            if(cond1 || cond2)scrambled= true;
        }
        return mp[key]=scrambled;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends