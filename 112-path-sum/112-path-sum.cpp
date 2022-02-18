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
    bool hasPathSum(TreeNode* root, int targetSum) {
       
        if(!root)
            return false;
        int temp=targetSum-root->val;
        if(!root->left && !root->right)
        return (temp==0? true:false);
        
        return hasPathSum(root->left, temp) || hasPathSum(root->right, temp);
    }
};