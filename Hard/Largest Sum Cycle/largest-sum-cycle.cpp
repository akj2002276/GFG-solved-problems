//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
long long largestSumCycle(int N, vector<int> edge)
  {
    // code here
    vector<int> vis(N,0);
    int ans=-1;
    for(int i=0; i<N; ++i) {
        if(!vis[i]) {
            set<int> ind;
            int sum=0;
            vector<pair<int,int>> pref;
            int j=i;
            while(1) {
                if(j<0 or j>=N or edge[j]==-1) break;
                ind.insert(j);
                sum+=j;
                pref.push_back({j,sum});
                vis[j]=1;
                j=edge[j];
                if(vis[j]==1) {
                    if(ind.find(j)!=ind.end()) {
                        int k=0;
                        for(; k<pref.size(); ++k) {
                            if(pref[k].first==j) {
                                break;
                            }
                        }
                        if(k==0) ans=max(ans,sum);
                        else ans=max(ans,sum-pref[k-1].second);
                        break;
                    }
                    else break;
                }
            }
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends