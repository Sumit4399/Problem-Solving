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
    
        void rev_inorder(TreeNode* root, int &prev)
    {
        if(!root)
            return;
        rev_inorder(root->right, prev);
        root->val+= prev;
        prev=root->val;
        rev_inorder(root->left, prev);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
       
        int prev=0;
        rev_inorder(root, prev);
        return root;
    }
};