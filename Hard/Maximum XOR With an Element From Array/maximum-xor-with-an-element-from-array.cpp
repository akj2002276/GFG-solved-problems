//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node{
  public:
  Node* link[2];
  bool isPresent(int bit)
  {
      return (link[bit]!=NULL);
  }
  void put(int bit)
  {
      link[bit]=new Node();
  }
  Node* next(int bit)
  {
      return link[bit];
  }
};
class Trie{
  Node* root;
  public:
  Trie(){
      root=new Node();
  }
  void insert(int x)
  {
      Node* newNode=root;
      for(int i=31;i>=0;i--)
      {
          int bit=(x>>i)&1;
          if(!newNode->isPresent(bit))
          newNode->put(bit);
          newNode=newNode->next(bit);
      }
  }
  int find(int x)
  {
      Node* newNode=root;
      int val=0;
      for(int i=31;i>=0;i--)
      {
          int bit=(x>>i)&1;
          if(newNode->isPresent(!bit))
          {
              val=(1<<i)|val;
              newNode=newNode->next(!bit);
          }
          else
          newNode=newNode->next(bit);
      }
      return val;
  }
};
// t.c=O(max(QlogQ, NlogN)) s.c= O(Q + N)
class Solution {
  public:
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<pair<int,pair<int,int>>>qu;
        int row=queries.size();
        for(int i=0;i<row;i++)
        qu.push_back({queries[i][1],{queries[i][0],i}});
        
        sort(qu.begin(),qu.end());
        Trie temp;
        int arrInd=0;
        vector<long long>ans(row,0);
        //t.c= q*32 + n*32
        for(int j=0;j<qu.size();j++)
        {
            int minV=qu[j].first;
            int num=qu[j].second.first;
            int ind=qu[j].second.second;
            while(arrInd<N && minV>=arr[arrInd])
            {
                temp.insert(arr[arrInd]);
                arrInd++;
            }
            // if minV>=arr[arrInd] no element inserted in trie
            if(arrInd==0)
            ans[ind]=-1;
            else
            ans[ind]=temp.find(num);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends