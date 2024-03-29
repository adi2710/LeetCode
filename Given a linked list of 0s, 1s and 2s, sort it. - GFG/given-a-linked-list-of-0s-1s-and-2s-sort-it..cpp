//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        Node *dummy = new Node(-1);
        Node *zero = dummy, *one = dummy, *two = dummy, *cur = head;
        while(cur != nullptr)
        {
            if(cur -> data == 0)
            {
                Node *next = zero -> next;
                zero -> next = cur;
                if(one == zero)
                    one = cur;
                if(two == zero)
                    two = cur;
                zero = zero -> next;
                cur = cur -> next;
                zero -> next = next;
            }
            else if(cur -> data == 1)
            {
                Node *next = one -> next;
                one -> next = cur;
                if(two == one)
                    two = cur;
                one = one -> next;
                cur = cur -> next;
                one -> next = next;
            }
            else{
                Node *next = two -> next;
                two -> next = cur;
                two = two -> next;
                cur = cur -> next;
                two -> next = next;
            }
        }
        head = dummy -> next;
        delete(dummy);
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends