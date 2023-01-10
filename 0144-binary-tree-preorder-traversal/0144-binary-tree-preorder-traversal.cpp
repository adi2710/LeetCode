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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        while(cur != nullptr)
        {
            if(cur -> left == nullptr)
            {
                ans.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                TreeNode *tmp = cur -> left;
                while(tmp -> right != nullptr && tmp -> right != cur)
                    tmp = tmp -> right;
                if(tmp -> right == nullptr)
                {
                    ans.push_back(cur -> val);
                    tmp -> right = cur;
                    cur = cur -> left;
                }
                else
                {
                    tmp -> right = nullptr;
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
};