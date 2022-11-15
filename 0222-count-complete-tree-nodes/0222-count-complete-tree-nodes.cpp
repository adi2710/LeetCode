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
    
    int findLeftHeight(TreeNode *root)
    {
        int ht = 0;
        while(root != nullptr)
        {
            root = root -> left;
            ht++;
        }
        return ht;
    }
    
    int findRightHeight(TreeNode *root)
    {
        int ht = 0;
        while(root != nullptr)
        {
            root = root -> right;
            ht++;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int lf = findLeftHeight(root -> left);
        int rt = findRightHeight(root -> right);
        
        if(lf == rt)
            return (1 << (lf + 1)) - 1; 
        
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};