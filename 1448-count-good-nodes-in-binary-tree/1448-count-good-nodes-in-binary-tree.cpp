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
    
    void pre(TreeNode* root, int &c, int maxi){
        
        if(root==NULL)
            return;
        
        if(root->val >= maxi)
        {
            c++;
            maxi= max(maxi, root->val);    
        }
        
        pre(root->left, c, maxi);
        pre(root->right, c, maxi);
    }
    
    int goodNodes(TreeNode* root) {
        
        int c=0;
        int maxi= root->val;
        
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        pre(root, c, maxi);
        return c;
    }
};