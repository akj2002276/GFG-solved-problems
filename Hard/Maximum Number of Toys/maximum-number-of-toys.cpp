//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
        // code here
        vector<int> ans;
        vector<pair<int,int>> arr;
        for(int i=0;i<N;i++){
            arr.push_back({A[i],i});
        }
        map <int,int> convert;
        sort(arr.begin(), arr.end());
        for(int i=0;i<N;i++){
            convert[arr[i].second] = i;
        }
        vector<int> pre(N,0);
        pre[0] = arr[0].first;
        for(int i=1;i<N;i++){
            pre[i] = pre[i-1] + arr[i].first;
        }
        for(auto query : Queries){
            int cost = query[0];
            int k = query[1];
            vector<int> temp;
            for(int i=0;i<k;i++){
                temp.push_back(query[i+2]);
            }
            int idx = upper_bound(pre.begin(), pre.end(), cost) - pre.begin();
            int sum = 0;
            int count = 0;
            for(auto it : temp){
                if(convert[it-1] < idx){
                    sum += arr[convert[it-1]].first;
                    count++;
                }
            }
            if(idx > 0){
                sum += cost - pre[idx-1];
            }
            else{
                sum += cost;
            }
            // cout<<sum<<" "<<count<<"\n";
            while(idx < N and sum > 0){
                if(sum - arr[idx].first >= 0){
                    bool flag = true;
                    for(auto it : temp){
                        if(convert[it-1] == idx){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        sum -= arr[idx].first;
                    }
                    else{
                        count++;
                    }
                    idx++;
                }
                else{
                    break;
                }
            }
            ans.push_back(idx - count);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends