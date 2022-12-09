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
    
    void findMinDiff(TreeNode* root, int mn, int mx, int &ans)
    {
        if(root == nullptr)
        {
            ans = max(ans, mx - mn);
            return;
        }
        mn = min(mn, root -> val);
        mx = max(mx, root -> val);
        findMinDiff(root -> left, mn, mx, ans);
        findMinDiff(root -> right, mn, mx, ans);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        findMinDiff(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
};