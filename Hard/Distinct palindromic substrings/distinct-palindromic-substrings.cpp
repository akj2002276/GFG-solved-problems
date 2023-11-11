//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
int palindromeSubStrs(string s)
    {
       unordered_set<string>st;
       int n=s.size();
       for(int i=0;i<n;i++)
       {
           int l=i;
           int r=i+1;
           string temp;
           while(l>=0 && r<n)
           {
               if(s[l]==s[r])
               {
                   temp.push_back(s[l]);
                    temp.push_back(s[r]);
                    l--;
                    r++ ;
                    st.insert(temp);
               }
               else
               break;
           }
           
           temp="";
           
           l=i-1;
           r=i+1;
           
           temp.push_back(s[i]);
           st.insert(temp);
           
           while(l>=0 && r<n)
           {
               if(s[l]==s[r])
               {
                   temp.push_back(s[l]);
                    temp.push_back(s[r]);
                    l--;
                    r++ ;
                    st.insert(temp);
               }
               else
               break;
           }
           
       }
       
       return st.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends