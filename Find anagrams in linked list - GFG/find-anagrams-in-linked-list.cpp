//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<int> freq1(26), freq2(26);
        for(char ch : s)
            freq1[ch - 'a']++;
        Node *l = head, *r = head;
        int p1 = 0, p2 = 0, n = s.size();
        vector<Node*> ans; 
        while(r != nullptr)
        {
            while(r != nullptr && p2 - p1 < n)
                freq2[r -> data - 'a']++, r = r -> next, p2++;
            if(freq1 == freq2)
            {
                Node *dummy = new Node(-1), *temp = dummy;
                for(Node *tmp = l; tmp != r; tmp = tmp -> next)
                {
                    temp -> next = new Node(tmp -> data);
                    temp = temp -> next;
                }
                ans.push_back(dummy -> next);
                delete(dummy);
                while(l -> next != r)
                {
                    freq2[l -> data - 'a']--;
                    l = l -> next;
                    p1++;
                }
            }
            freq2[l -> data - 'a']--;
            l = l -> next;
            p1++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends