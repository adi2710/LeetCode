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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> nums(n);
            for(int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node == nullptr)
                    nums[i] = -1000;
                else{
                    nums[i] = node -> val;
                    q.push(node -> left);
                    q.push(node -> right);
                }
            }
            for(int i = 0; i < n / 2; i++)
            {
                if(nums[i] != nums[n - i - 1])
                    return false;
            }
        }
        return true;
    }
};