//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    // code here
	    vector<vector<int>> cnt(r,vector<int> (c,0));
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(i == 0){
	                //copy the first rows as it is
	                cnt[i][j] = mat[i][j];
	            }
	            else{
    	            if(mat[i][j] == 0){
    	                cnt[i][j] = 0;//discontinuity of ones
    	            }
    	            else{
    	                cnt[i][j] = mat[i][j]+cnt[i-1][j];
    	            }
	            }
	        }
	    }
	   // I got the cnts array
	   // calculate the largest rectangle ending at each row after swapping cleverly based on sorting
	   int ans = 0;
	   for(int i=0; i<r; i++){
           sort(cnt[i].begin(),cnt[i].end());
           int minHeight = INT_MAX;
	       for(int j=c-1,width = 1; j>=0; j--,width++){
	           minHeight = min(minHeight,cnt[i][j]);
	           if(minHeight == 0){
	               // no need to check further to the left
	               break;
	           }
	           else{
	               int area = width*minHeight;
	               ans = max(ans,area);
	           }
	       }
	   }
	   return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}

// } Driver Code Ends