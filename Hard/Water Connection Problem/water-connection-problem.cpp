//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    void dfs(int vertex,pair<int,int> graph[], int &last, int &mpipe){
        
        pair<int, int> child = graph[vertex];
        if(child.first==0 && child.second==0) return;
        mpipe = min(mpipe, child.second);
        last=child.first;
        dfs(child.first,graph,last, mpipe);
        
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        pair<int,int> graph[n+1];
        vector<bool> present(n+1,false);
        vector<int> indegree(n+1,0);
        
        for(int i=0; i<p; ++i){
            ++indegree[b[i]];
            graph[a[i]]= {b[i],d[i]};
            present[a[i]]=true;
            present[b[i]]=true;
        }
        
        vector<vector<int>> ans;
        for(int i=1; i<=n; ++i){
            if(indegree[i]==0 && present[i]){
                int last;
                int mpipe= INT_MAX;
                dfs(i, graph, last, mpipe);
                ans.push_back({i,last,mpipe});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends