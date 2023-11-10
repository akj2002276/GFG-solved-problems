//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
            vector<int> ans;
    int size1 = array1.size();
    int size2 = array2.size();
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (array1[i] <= array2[j])
        {
            ans.push_back(array1[i]);
            i++;
        }
        else
        {
            ans.push_back(array2[j]);
            j++;
        }
    }
    while (i < size1)
    {
        ans.push_back(array1[i]);
        i++;
    }
    while (j < size2)
    {
        ans.push_back(array2[j]);
        j++;
    }
    int s = 0, e = ans.size() - 1;
    while (e - s > 1)
    {
        s++;
        e--;
    }
    double temp=ans[s]+ans[e];
    double val = temp/ 2;
    return val;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends