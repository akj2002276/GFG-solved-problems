//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends



class Solution {
public:
   void solve(vector<vector <pair<int,int>>> list, int i, int len, int k, vector <bool> vis, bool &ans) {
        if(len >= k) {
            ans = true;
            return;
        }
        
        if(ans) return;
        vis[i] = true;
        
        for(auto p: list[i]) {
            if(!vis[p.first]) {
                solve(list, p.first, len + p.second, k, vis, ans);
            }
        }
    } 
    
    bool pathMoreThanK(int V, int E, int k, int *a) {
        
        vector < vector < pair <int, int> > > list(V);
        
        for(int i = 0; i < 3*E; i += 3) {
            list[*(a + i)].push_back({*(a + i + 1), *(a + i + 2)});
            list[*(a + i + 1)].push_back({*(a + i), *(a + i + 2)});
        }
        
        vector <bool> vis(V, false);
        bool ans = false;
        solve(list, 0, 0, k, vis, ans);
        return ans;
    } 

};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends