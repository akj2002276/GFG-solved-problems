//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int minCandy(int N, vector<int> &ratings) {
        // code here
        //o(2*N)
        //o(N) SC
        
        vector<int>ans(N,1);
        
        for(int i=1;i<N;i++)
        {
            if(ratings[i]>ratings[i-1]) ans[i]=1+ans[i-1];  //left neighbr
        }
        for(int i=N-2;i>=0;i--)
        {//right neighbr
        if(i==0) { //edge case
            if(ratings[i]>ratings[1]) ans[i]=1+ans[1]; break;
        }
            if(ratings[i]>ratings[i+1]) 
            {
                if(ans[i]<=ans[i+1]) ans[i] = 1+ans[i+1];
            }
        }
        
        int sum=0;
        for(int i:ans) sum+=i;
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends