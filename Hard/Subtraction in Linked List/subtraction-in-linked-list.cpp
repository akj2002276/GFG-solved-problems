//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method


int length(Node* temp){
    int count =0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
struct Node *reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if (head == NULL || head->next == NULL)
            return head;
        Node *temp;
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

Node *subLinkedList(Node *l1, Node *l2)
{
    // Remove leading zeros from both input linked lists
    while (l1->data == 0 && l1->next)
    {
        l1 = l1->next;
    }
    while (l2->data == 0 && l2->next)
    {
        l2 = l2->next;
    }

    // Get the lengths of the linked lists
    int len1 = length(l1);
    int len2 = length(l2);

    Node *small, *big, *temp1, *temp2;
    if (len1 < len2)
    {
        // Choose the smaller linked list as "small" and the larger as "big"
        small = l1;
        big = l2;
    }
    else if (len2 < len1)
    {
        small = l2;
        big = l1;
    }
    else
    {
        // If lengths are equal, compare each digit of the two numbers
        temp1 = l1;
        temp2 = l2;
        while (temp1 && temp2)
        {
            if (temp1->data < temp2->data)
            {
                small = l1;
                big = l2;
                break;
            }
            else if (temp2->data < temp1->data)
            {
                small = l2;
                big = l1;
                break;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        if (!temp1 && !temp2)
        {
            // If both numbers are equal, return a dummy node with value 0
            Node *dummy = new Node(0);
            return dummy;
        }
    }

    // Reverse the linked lists for easier subtraction
    big = reverseList(big);
    small = reverseList(small);

    temp1 = big;
    temp2 = small;

    int borrow = 0;

    while (temp1)
    {
        if (temp1 && !temp2 && borrow)
        {
            // If there's a borrow but no more digits in temp2
            if (temp1->data == 0)
            {
                temp1->data = temp1->data + 10 - borrow;
                borrow = 1;
                temp1 = temp1->next;
            }
            else
            {
                temp1->data = temp1->data - borrow;
                break;
            }
        }
        else if (temp1->data - borrow >= temp2->data)
        {
            // Regular subtraction
            temp1->data = temp1->data - borrow - temp2->data;
            borrow = 0;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            // Borrow situation
            temp1->data = temp1->data + 10 - borrow - temp2->data;
            borrow = 1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 && !temp2 && !borrow)
        {
            // Break if temp2 is exhausted and no more borrowing
            break;
        }
    }

    // Reverse the big back to the original order
    big = reverseList(big);

    // Remove leading zeros from the result
    if (big->data == 0)
    {
        big = big->next;
    }

    return big;
}