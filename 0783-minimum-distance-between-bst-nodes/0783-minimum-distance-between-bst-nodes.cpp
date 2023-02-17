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
    int minDiffInBST(TreeNode* root) {
        int prev = -1, ans = INT_MAX;
        TreeNode *cur = root;
        while(cur != nullptr)
        {
            if(prev != -1)
                ans = min(ans, cur -> val - prev);
            if(cur -> left == nullptr)
            {
                prev = cur -> val;
                cur = cur -> right;
            }    
            else
            {
                TreeNode *tmp = cur -> left;
                while(tmp -> right != nullptr && tmp -> right != cur)
                    tmp = tmp -> right;
                if(tmp -> right == nullptr){
                    tmp -> right = cur;
                    cur = cur -> left;
                }
                else
                {
                    prev = cur -> val;
                    tmp -> right = nullptr;
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
};