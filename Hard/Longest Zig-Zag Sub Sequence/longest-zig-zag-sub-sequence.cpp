//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
	public:
		int ZigZagMaxLength(vector<int> &nums){
	int ins=1;
	int des=1;
	for(int i=0;i<nums.size()-1;i++){
		if(nums[i]>nums[i+1]){
		   ins=des+1;
		}
		else if(nums[i]<nums[i+1]){
		    des=ins+1;
		}
	}
	return max(des,ins);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends