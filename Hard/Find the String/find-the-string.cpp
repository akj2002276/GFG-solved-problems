//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    string res;
    int count=1; 
    int k,n,total;
    map<string,bool> mp;
    
    void dfs(string &curr,string &ans){
        
        if(count >= total){
            if(count==total) res = ans;
            return;
        }

        // take prev string and remove first char and add new char at the end and check if it is forming new 
        for(int i=k-1;i>=0;i--){
            
            string temp = curr.substr(1);
            temp+=(i+'0');
        
            // already visited 
            if(!mp.count(temp)){
                count++;
                mp[temp]=1;
                
                ans+=(i+'0');
                
                dfs(temp,ans);
            } 
        }
    }
    
    
    string findString(int n, int k) {

        // total diff ways = k^n
        this->k=k;
        this->n=n;
        this->total=pow(k,n);
        
        // form the graph 
        string start="",ans="";
        for(int i=0;i<n;i++) start+="0";
        mp[start]++;
        
        dfs(start,start);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends