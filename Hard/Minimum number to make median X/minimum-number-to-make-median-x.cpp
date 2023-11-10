//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minimumAppend(int arr[], int num, int x)
    {
        // Complete the function
                int e = 0, l = 0, h = 0;
        int greatest_smaller = INT_MIN;
        int smallest_greater = INT_MAX;
        for(int i = 0; i<num; i++){
            if(arr[i] == x)
                e++;
            else if(arr[i] < x){
                l++;
                greatest_smaller = max(greatest_smaller, arr[i]);
            }
            else{
                h++;
                smallest_greater = min(smallest_greater, arr[i]);
            }
        }
        
        int to_add = 0;
        if(num % 2 == 0){
            to_add = abs(h -l) - e +1;
            if(e!= 1 && greatest_smaller + smallest_greater == 2*x)
                to_add--;
        }
        else{
            if(e == 1 || greatest_smaller + smallest_greater == 2*x)
                to_add = abs(h - l);
            else if(greatest_smaller + smallest_greater > 2*x){
                if(l < h)
                    to_add = h - l + 1;
                else
                    to_add = l - h;
            }
            else{
                if(l < h)
                    to_add = h - l;
                else
                    to_add = l - h + 1;
            }
        }
        return to_add;
    }

};

//{ Driver Code Starts.
int main() {
    
	int T;
	cin>>T;
	while(T--){
	    int num, x;
	    cin>>num>>x;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	     Solution obj;
	    cout << obj.minimumAppend(arr, num, x) << endl;
	    
	}
}
// } Driver Code Ends