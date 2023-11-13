//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int* rank;
    int* parent;
  public:
    void Union(int node1, int node2){
        int Pnode1=Find(node1);
        int Pnode2=Find(node2);
        if(Pnode1==Pnode2){
            return;
        }
        if(rank[Pnode1]>rank[Pnode2]){
            parent[Pnode2]=Pnode1;
        }
        else if(rank[Pnode1]<rank[Pnode2]){
            parent[Pnode1]=Pnode2;
        }
        else{
            parent[Pnode1]=Pnode2;
            rank[Pnode2]++;
        }
    }
    
    int Find(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=Find(parent[node]);
    }
    
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
        rank=new int[n+1];
        parent=new int[n+1];
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        vector<string> res;
        for(auto &m: mix){
            bool dangerous=false;
            for(auto &dngr: danger){
                int Pdngr1=Find(dngr[0]);
                int Pdngr2=Find(dngr[1]);
                int Psol1=Find(m[0]);
                int Psol2=Find(m[1]);
                if((Pdngr1==Psol1 && Pdngr2==Psol2) || (Pdngr1==Psol2 && Pdngr2==Psol1)){
                    dangerous=true;
                    break;
                }
            }
            if(dangerous==false){
                Union(m[0],m[1]);
                res.push_back("Yes");
            }
            else{
                res.push_back("No");
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends