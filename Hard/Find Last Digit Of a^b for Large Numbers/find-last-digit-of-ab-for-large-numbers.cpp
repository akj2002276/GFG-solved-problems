//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int getLastDigit(string a, string b) {
        
        if(a.size()==1 && a[0]=='0' && b.size()==1 && b[0]=='0')
        return 1;
        if(a.size()==1 && a[0]=='0')
        return 0;
        if(b.size()==1 && b[0]=='0')
        return 1;
        
        int A = a[a.size()-1]-'0';
        int B=0;
        
        for(int i=0;i<b.size();i++){
            B=B*10+(b[i]-'0');
            B%=4;
            
        }
        
        if(B==0)
        B=4;
        
        int ans =pow(A,B);
        ans%=10;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends