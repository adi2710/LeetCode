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
    
    int findMaxSumPath(TreeNode *root, int &ans)
    {
        if(root == nullptr)
            return 0;
        
        int left = findMaxSumPath(root -> left, ans);
        int right = findMaxSumPath(root -> right, ans);
        
        int maxSum = max({left + root -> val, right + root -> val, root -> val});
        
        ans = max({ans, maxSum, left + root -> val + right});
        return maxSum;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxSumPath(root, ans);
        return ans;
    }
};