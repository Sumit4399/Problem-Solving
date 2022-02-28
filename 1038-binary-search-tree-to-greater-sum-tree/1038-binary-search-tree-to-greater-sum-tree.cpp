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
    
    void inorder(TreeNode* root, int &prev)
    {
        if(!root)
            return;
        inorder(root->right, prev);
        root->val+= prev;
        prev=root->val;
        inorder(root->left, prev);
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        
        int prev=0;
        inorder(root, prev);
        return root;
    }
};