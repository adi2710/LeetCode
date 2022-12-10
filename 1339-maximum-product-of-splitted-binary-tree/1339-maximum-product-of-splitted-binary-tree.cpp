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
    
    int findTotalSum(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        
        return root -> val + findTotalSum(root -> left) + findTotalSum(root -> right);
    }
    
    int maxSplit(TreeNode *root, int totSum, long long &ans)
    {
        if(root == nullptr)
            return 0;
        
        int left = maxSplit(root -> left, totSum, ans);
        int right = maxSplit(root -> right, totSum, ans);
        
        ans = max({ans, 1ll * left * (totSum - left), 1ll * right * (totSum - right)});
        
        return left + right + root -> val;
    }
    
    int maxProduct(TreeNode* root) {
        long long ans = 0;
        int totSum = findTotalSum(root);
        maxSplit(root, totSum, ans);
        const int MOD = 1e9 + 7;
        return ans % MOD;
    }
};