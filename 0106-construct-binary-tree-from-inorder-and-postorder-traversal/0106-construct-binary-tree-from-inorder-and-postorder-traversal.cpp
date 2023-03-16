/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* solve(int l, int r, int &root, vector<int> &inorder, vector<int> &postorder)
    {
        if(l > r)
            return nullptr;
        
        int mid = l;
        root--;
        while(mid <= r && inorder[mid] != postorder[root]) mid++;
        
        TreeNode *node = new TreeNode(postorder[root]);
        node -> right = solve(mid + 1, r, root, inorder, postorder);
        node -> left = solve(l, mid - 1, root, inorder, postorder);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int root = postorder.size();
        return solve(0, inorder.size() - 1, root, inorder, postorder);
    }
};