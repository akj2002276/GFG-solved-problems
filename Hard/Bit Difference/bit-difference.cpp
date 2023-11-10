//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int countBits(int N, long long int A[])
    {
        
        long long ans=0;
        int mod=1000000007;
        
        for(int i=31;i>=0;i--)
        {
            long long set=0,nonset=0;
            
            for(long long int j=0;j<N;j++)
            {
                if((A[j]>>i)&1!=0)
                {
                    set++;
                }
                else
                {
                    nonset++;
                }
            }
            
            if(nonset==N)
            {
                continue;
            }
            
            ans=(ans+(set*nonset*2)%mod)%mod;
            
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends