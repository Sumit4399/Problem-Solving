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
        
        v.push_back(root);
        inorder(root->left, v);
        inorder(root->right, v);
        
    }
    
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> v;
        inorder(root, v);
        // TreeNode* temp = root;
        // sort(v.begin(), v.end());
        for(int i=1;i<v.size();i++) {
            root->right = new TreeNode();
            root->right = v[i];
            root->left=NULL;
            root = root->right;
        }
        
    }
};