//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
    void solve(int arr[],int n,int i,int j,int &k){
        if(j>=n) return;
        int x=arr[i],y=arr[j];
        solve(arr,n,i+1,j+1,k);
        arr[k--]=y;
        arr[k--]=x;
    }
    void shuffleArray(int arr[],int n)
    {
        int k=n-1;
        solve(arr,n,0,n/2,k);
        return;
    }
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends