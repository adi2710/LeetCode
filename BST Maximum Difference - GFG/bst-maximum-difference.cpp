//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    Node* findTarget(Node *root, int target, int &sum1)
    {
        if(root == nullptr)
            return nullptr;
        if(root -> data == target)
            return root;
        sum1 += root -> data;
        if(root -> data < target)
            return findTarget(root -> right, target, sum1);
        return findTarget(root -> left, target, sum1);
    }
    
    void findMaxDiff(Node *root, Node *tgt, int sum1, int sum2, int &ans)
    {
        if(root == nullptr)
            return;
        if((root -> left == nullptr) && (root -> right == nullptr))
        {
            if(root != tgt)
                sum2 += root -> data;
            ans = max(ans, sum1 - sum2);
            return;
        }
        if(root != tgt)
            sum2 += root -> data;
        findMaxDiff(root -> left, tgt, sum1, sum2, ans);
        findMaxDiff(root -> right, tgt, sum1, sum2, ans);
    }
    
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum1 = 0, ans = INT_MIN;
        Node *tgt = findTarget(root, target, sum1);
        if(tgt == nullptr)
            return -1;
        findMaxDiff(tgt, tgt, sum1, 0, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends