//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    node *reverse(node *cur, node *last)
    {
        node *prev = nullptr;
        while(cur != last)
        {
            node *next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    public:
    node *reverse (node *head, int k)
    { 
        // Complete this method
        if(head == nullptr || head -> next == nullptr)
            return head;
        node *dummy = new node(-1);
        dummy -> next = head;
        node *cur = head, *prev = dummy;
        while(cur != nullptr)
        {
            node *next = cur;
            int cnt = 0;
            while(cnt < k && next != nullptr)
            {
                next = next -> next;
                cnt++;
            }
            node *revHead = reverse(cur, next);
            prev -> next = revHead;
            prev = cur;
            cur = next;
        }
        head = dummy -> next;
        delete(dummy);
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends