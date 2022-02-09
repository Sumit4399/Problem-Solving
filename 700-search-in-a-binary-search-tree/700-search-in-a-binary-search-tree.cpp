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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        //TreeNode* v;
        if(root==NULL)
            return root;
        while(root)
        {
            if(root->val == val)
                return root;
            else if(val<root->val)
            //return searchBST(root->left, val);
            root= root->left;
            else 
            //return searchBST(root->right, val);
            root= root->right;
        }
        return root;
    }
};