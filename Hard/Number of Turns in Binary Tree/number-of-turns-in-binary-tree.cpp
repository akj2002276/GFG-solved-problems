//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
 int turns(Node *root, int a,int b,bool flag)
   {
       if(root)
       {
           if(root->data==a || root->data==b)return 0;
           
           if(flag==false)
           {
               return min(turns(root->left,a,b,false),1+turns(root->right,a,b,true)) ;
           }
           else
           {
                return min(1+turns(root->left,a,b,false),turns(root->right,a,b,true)) ;
           }
       }
       
       return 1e3 ;
   }
    Node *lca(Node *root, int a, int b)
    {
        if(root==NULL)
        return NULL;
        
        if(root->data==a || root->data==b) return root;
        
       Node *left_lca =lca(root->left,a,b);
        Node *right_lca =lca(root->right,a,b);
        
        if(left_lca && right_lca) return root ;
        
        return (left_lca !=NULL) ? left_lca : right_lca ;
    }
    int NumberOFTurns(struct Node* root, int x, int y)
    {
        Node *temp = lca(root,x,y);
        if(temp->data!=x && temp->data!=y) 
        {
            int a=turns(temp->left,x,y,false);
            int b=turns(temp->right,x,y,true);
            return a+b+1;
        }
        else 
        {
               
           int a=turns(temp->left,x,y,false);
           int b=turns(temp->right,x,y,true);
           
           if(a==1000 && b==1000) return -1 ;
           int c=a+b-1000;
           if(c==0) return -1 ;
           
           return c ;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends