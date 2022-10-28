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
    
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    
    int dfs(TreeNode *root, bool prev)
    {
        if(root == nullptr)
            return 0;
        if(dp.find(root) != dp.end() && dp[root].find(prev) != dp[root].end())
            return dp[root][prev];
            
        if(prev)
            return dp[root][prev] = dfs(root -> left, 0) + dfs(root -> right, 0);
        return dp[root][prev] = max(root -> val + dfs(root -> left, 1) + dfs(root -> right, 1), dfs(root -> left, 0) + dfs(root -> right, 0));
    }
    
    int rob(TreeNode* root) {
        return dfs(root, 0);
    }
};