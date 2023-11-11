//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

public:

int wordLadderLength(string startword, string targetword, vector<string>& words) {
        // Code here
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            
        }
        mp.erase(startword);
        queue<pair<string,int>>q;
        q.push({startword,1});
        while(!q.empty()){
            string s=q.front().first;
            int ans=q.front().second;
            q.pop();
            if(s==targetword){
                return ans;
            }
            for(int i=0;i<s.size();i++){
                char org=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(mp.count(s)){
                        q.push({s,ans+1});
                        mp.erase(s);
                    }
                }
                s[i]=org;
            }
        }
        return 0;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends