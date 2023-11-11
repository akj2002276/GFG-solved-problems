//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool isp(int col,int i,vector<int> &row,vector<int> &ld,vector<int> &rd,int n)
    {
        if(row[i]==1)return false;
        if(ld[i+col]==1)return false;
        if(rd[n-1+col-i]==1)return false;
        return true;
    }
    void solve(int col,vector<int> &row,vector<int> &ld,vector<int> &rd,vector<int> &val,vector<vector<int>> &ans,int n)
    {
        if(col>n-1)
        {
            ans.push_back(val);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isp(col,i,row,ld,rd,n)==true)
            {
                row[i]=1;
                ld[i+col]=1;
                rd[n-1+col-i]=1;
                val.push_back(i+1);
                solve(col+1,row,ld,rd,val,ans,n);
                val.pop_back();
                row[i]=0;
                ld[i+col]=0;
                rd[n-1+col-i]=0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> val;
        vector<vector<int>> ans;
        vector<int> row(n,0);
        vector<int> ld((2*n)-1,0);
        vector<int> rd((2*n)-1,0);
        solve(0,row,ld,rd,val,ans,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends