#User function Template for python3
class Solution:
    def isSumString(self, S):
        def is_valid(s1, s2, s):
            while s:
                s3 = str(int(s1) + int(s2))
                if not s.startswith(s3):
                    return False
                s = s[len(s3):]
                s1, s2 = s2, s3
            return True
        n = len(S)
        for i in range(1, n):
            for j in range(1, n - i):
                s1, s2 = S[:i], S[i:i+j]
                if is_valid(s1, s2, S[i+j:]):
                    return 1
        return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        
        print(ob.isSumString(S))
# } Driver Code Ends