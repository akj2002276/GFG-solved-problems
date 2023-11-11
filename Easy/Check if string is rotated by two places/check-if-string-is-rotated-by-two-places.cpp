//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length() != str2.length()){
            return 0;
        }
        if(str1 == str2){
            return 0;
        }
        if(str1.length()<=2 && str2.length()<=2){
            return 0;
        }
        // Your code here
        string res = str2 + str2;
        return res.find(str1) != string::npos;
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends