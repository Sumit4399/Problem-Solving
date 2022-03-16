/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //assuming both the keys are present in tree
        if(root==NULL)
        return NULL;
        
        //if any one of the key is equal to root
        if(root==p || root==q)
        return root;
        
        //finding the key from left and right subtree
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right =lowestCommonAncestor(root->right, p, q);
        
        //if(both of the keys are present in left and right subtree)
        if(left && right)
        return root;
        
        //if(both are present in left or right subtree)
        return (left!=NULL? left : right);

    }
};