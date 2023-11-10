//{ Driver Code Starts
                               //Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int ans=INT_MAX;
    vector<int> l;
    vector<int> r;
     void helper(vector<int>& arr,int index,int leftsum,int rightsum,vector<int>& left,vector<int>& right,int n){
         if(index==n){
             int k=(n+1)/2;
             if(left.size()<=k && right.size()<=k){
                 int k=abs(leftsum-rightsum);
                 if(k<ans){
                     ans=k;
                     l=left;
                     r=right;
                 }
             }
             return;
         }
         left.push_back(arr[index]);
         helper(arr,index+1,leftsum+arr[index],rightsum,left,right,n);
         left.pop_back();
         right.push_back(arr[index]);
         helper(arr,index+1,leftsum,rightsum+arr[index],left,right,n);
         right.pop_back();
     }
     vector<vector<int>> minDifference(vector<int>& arr, int n){
          vector<int> left;
          vector<int> right;
          helper(arr,0,0,0,left,right,n);
          vector<vector<int>> ans;
          ans.push_back(l);
          ans.push_back(r);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        vector<vector<int>> ans = obj.minDifference(arr,n);
        
        long long s1=0, s2=0;

        for(int i=0;i<ans[0].size();i++) s1+=ans[0][i];
        for(int i=0;i<ans[1].size();i++) s2+=ans[1][i];
        
        if(s1>s2) swap(s1,s2);

        cout<<s1<<"\n"<<s2<<"\n";
    }
}
                               
// } Driver Code Ends