//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

 

typedef struct Trie{
    bool isend;
    int count;
    struct Trie* child[2];
}Trie;

Trie* getNode(){
    Trie* temp = new Trie;
    temp->isend = false;
    temp->count = 0;

    for(int i = 0 ; i < 2; ++i){
        temp->child[i] = NULL;
    }

    return temp;
}

int insert(Trie* root,vector<int>v){
    Trie* curr = root;

    for(int i = 0; i < v.size(); i++){
        int index = v[i];

        if(curr->child[index] == NULL){
            curr->child[index] = getNode();
        }

        curr = curr->child[index];
    }
    
    if(!curr->isend){
        curr->isend = true;
        return 1;
    }
    else{
        return 0;
    }
}

class Solution{
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N){
    Trie* root = getNode();
    vector<int>res = {};
    for(int i = 0; i < M;i++){
        if(insert(root,matrix[i]) == 0){
            res.push_back(i);
        }
    }
    
    return res;
}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends