//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // if we visualize it forms a fibonacci pattern
  int m=pow(10,9)+7;
  int fib(long long n)
{
    long long F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return (int)F[0][0]%m;
}
 
void power(long long F[2][2], long long n)
{
    if(n == 0 || n == 1)
       return;
    long long M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
 
void multiply(long long F[2][2], long long M[2][2])
{
    long long x = ((F[0][0] * M[0][0])%m + (F[0][1] * M[1][0])%m)%m;
    long long y = ((F[0][0] * M[0][1])%m + (F[0][1] * M[1][1])%m)%m;
    long long z = ((F[1][0] * M[0][0])%m + (F[1][1] * M[1][0])%m)%m;
    long long w = ((F[1][0] * M[0][1])%m + (F[1][1] * M[1][1])%m)%m;
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
    int countStrings(long long int N) {
        // Code here
      int n = fib(N+2);
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends