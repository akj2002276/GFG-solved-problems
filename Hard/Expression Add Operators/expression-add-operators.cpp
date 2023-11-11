//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
private:
    void solve(int val, int prev, int target, string &num, string output, int idx, vector<string>&ans){
        if(idx >= num.size()){
            if(val == target){
                ans.push_back(output);
            }
            return;
        }
        string temp = "";
        int curr_val = 0;
        for(int i=idx; i<num.size(); i++){
            temp += num[i];
            curr_val = curr_val*10 + (num[i] - '0');
            if(idx == 0){
                solve(curr_val, curr_val, target, num, temp, i+1, ans);
            }
            else{
                solve(val+curr_val, curr_val, target, num, output+"+"+temp, i+1, ans);
                solve(val-curr_val, -1*curr_val, target, num, output+"-"+temp, i+1, ans);
                solve(val-prev+prev*curr_val, prev*curr_val, target, num, output+"*"+temp, i+1, ans);
            }
            if(num[idx]=='0') break;
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string output;
        int idx = 0;
        int val = 0;
        int prev = 0;
        solve(val, prev, target, num, output, idx, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends