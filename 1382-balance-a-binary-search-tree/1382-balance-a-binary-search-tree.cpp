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
    
    void inorder(TreeNode* root, vector<TreeNode*>&v)
    {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    TreeNode* build(vector<TreeNode*>&v, int l, int r)
    {
        if(l>r)
            return NULL;
        
        int mid= (l+r)/2;
        TreeNode* temp= v[mid];
        
        temp->left= build(v, l, mid-1);
        temp->right= build(v, mid+1, r);
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<TreeNode*> v;
        inorder(root, v);
        int start=0;
        int end=v.size()-1;
        
        return build(v,start, end);
    }
};