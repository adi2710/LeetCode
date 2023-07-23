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
    
    vector<TreeNode*> generate(int n, unordered_map<int, vector<TreeNode*>> &mp)
    {
        if(n & 1 ^ 1)
            return {};
        
        if(n == 1)
            return {new TreeNode(0)};
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        vector<TreeNode*> ans;
        
        for(int i = 0; i < n; i++)
        {
            int j = n - i - 1;
            for(TreeNode* lf : generate(i, mp))
            {
                for(TreeNode* rt : generate(j, mp))
                {
                    TreeNode *root = new TreeNode(0, lf, rt);
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mp;
        return generate(n, mp);
    }
};