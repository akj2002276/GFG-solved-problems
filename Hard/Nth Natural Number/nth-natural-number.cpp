//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
public:
    long long findNth(long long N)
    {
        // code here.
        long long ans = 0,
                  multiplier = 1;
                  
        while (N) {
            ans += (N%9) * multiplier;
            N /= 9;
            multiplier *= 10;
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}


// } Driver Code Ends