//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int isSuperSimilar(int n, int m, vector<vector<int>>& mat, int x)

    {

        vector<vector<int>> v(n);

        x=x%m;

        for(int i=0;i<n;i++){

            if(i%2==0){

                for(int j=m-x;j<m;j++) v[i].push_back(mat[i][j]);

                for(int j=0;j<m-x;j++) v[i].push_back(mat[i][j]);

            }

            else {

                for(int j=x;j<m;j++) v[i].push_back(mat[i][j]);

                for(int j=0;j<x;j++) v[i].push_back(mat[i][j]);

            }

        }

        if(v==mat) return 1;

        return 0;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        int x;
        cin >> x;
        
        Solution ob;
        cout<<ob.isSuperSimilar(n,m,mat,x)<<endl;
    }
    return 0;
}
// } Driver Code Ends