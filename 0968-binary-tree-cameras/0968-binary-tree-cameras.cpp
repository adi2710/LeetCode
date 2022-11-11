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
    
    #define no_camera_needed 1
    #define has_camera 2
    #define need_camera 3
    
    int minCameraCount(TreeNode *root, int &ans)
    {
        if(root == nullptr)
            return no_camera_needed;
        
        int lf = minCameraCount(root -> left, ans);
        int rt = minCameraCount(root -> right, ans);
        
        if(lf == need_camera || rt == need_camera)
        {
            ans++;
            return has_camera;
        }
        else if(lf == no_camera_needed && rt == no_camera_needed)
            return need_camera;
        return no_camera_needed;
    }
    
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(minCameraCount(root, ans) == need_camera)
            ans++;
        return ans;
    }
};