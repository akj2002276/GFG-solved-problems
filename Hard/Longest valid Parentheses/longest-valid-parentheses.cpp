//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int maxLength(string S){
      stack<int>s;
      s.push(-1);
      int maxLen=0;
      for(int i=0;i<S.length();i++){
          char ch=S[i];
      
         // IF it is open bracket simply push its index 
         if(ch=='('){
          s.push(i);
         }
         
         else{
          // if it is close bracket first pop the top element and check the two
          // condition whether the stack is empty or not 
          s.pop();
          if(s.empty()){
              s.push(i);
          }
          // finding the maxium length by subtracting the current index- stack top
          // and stroing it's maximum value 
          else{
               int len=i-s.top();
               maxLen=max(len,maxLen);
               
          }
          
          
      }
    
   }
   return maxLen;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends