//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int sum = 0;
        int totalsum = 0;
        string s = "";
        for(int i = 0; i < N; i++){
            s = to_string(arr[i]);
            for(char c : s){
                sum = sum + c - '0';
            }
            totalsum = sum + totalsum;
            sum = 0;
        }
        if(totalsum % 3 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends