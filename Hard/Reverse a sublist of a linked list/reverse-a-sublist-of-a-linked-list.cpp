//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
Node* reverseBetween(Node* head, int m, int n)
    {
        //go to the mth node
        Node * tmp1 = head;
        Node * tmp2 = head;
        int tm = m-1;
        while(tm && tmp1){
            tmp2 = tmp1;
            tmp1 = tmp1->next;
            tm--;
        }
        
        int diff = n-m;
        Node * fcn = head;
        int tn = n;
        
        //keep a pntr at node which is after nth node
        while(tn && fcn){
            fcn = fcn->next;
            tn--;
        }
        
        //swap the list from mth to nth node
        Node * p = fcn;
        Node * c = tmp1;
        
        while(diff+1 && tmp1){
            c = tmp1->next;
            tmp1->next = p;
            p = tmp1;
            tmp1 = c;
            diff--;
        }
        
        if(m != 1){
            Node * ht = tmp2;
            ht->next = p;
        }
        else{
            head = p;
        }
        return head;
        
        
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends