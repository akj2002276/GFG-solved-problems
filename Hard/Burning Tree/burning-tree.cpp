//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>&nodeToParent){
        Node* targetNode = NULL;
        
        queue<Node*>q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            
            if(current->data == target) targetNode = current;
            if(current->left){
                nodeToParent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                nodeToParent[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }
    
    void burnTree(Node* root, map<Node*, Node*>&nodeToParent, int &time){
        map<Node*, bool>visited;
        queue<Node*>q;
        
        q.push(root);
        visited[root] = true;

        while(!q.empty()){
            bool flag = false;
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* current = q.front();
                q.pop();
                
                if(current->left && !visited[current->left]){
                    flag = true;
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    flag = true;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(nodeToParent[current] && !visited[nodeToParent[current]]){
                    flag = true;
                    q.push(nodeToParent[current]);
                    visited[nodeToParent[current]] = true;
                }
            }
            if(flag) time++;
        }
    }
    
  public:
    int minTime(Node* root, int target) {
        int time = 0;
        map<Node*, Node*>nodeToParent;
        
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        burnTree(targetNode, nodeToParent, time);
        
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends