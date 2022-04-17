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
    
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int> v;
        inorder(root, v);
        
        //creating new tree with only right nodes
        TreeNode* res= new TreeNode(v[0]);
        TreeNode* temp=res;
        for(int i=1; i<size(v); i++)
        {
            res->right= new TreeNode(v[i]);
            res=res->right;
        }
        
        return temp;
    }
};