//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

public:

    long buzzTime(long N, long M, long L, long H[], long A[])

    {

        // code here

        long beg=0;

        long end=max(M,L);

        long ans=0;

        while(beg<=end)

        {

            long mid=(beg+(end-beg)/2);

            //calculating speed

            long speedtrack=0;

            for(int i=0;i<N;i++)

            {

                long indispeed=H[i]+mid*A[i];

                if(indispeed>=L)

                {

                    speedtrack+=indispeed;

                }

            }

            if(speedtrack<=M)

            {

                ans=max(ans,mid);

                beg=mid+1;

            }

            else

            {

                end=mid-1;

            }

        }

        return ans+1;

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends