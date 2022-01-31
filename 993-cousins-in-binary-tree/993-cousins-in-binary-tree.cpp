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
    
    pair<TreeNode*, int> inorder(TreeNode* root, TreeNode* parent,
                                int n, int depth, pair<TreeNode*, int> &p)
    {
        if(root==NULL)
            return {};
        inorder(root->left, root, n, 1+depth, p);
        if(root->val==n)
        {
            p.first=parent;
            p.second=depth;
            return p;
        }
        inorder(root->right, root, n, 1+depth, p);
        return p;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        pair<TreeNode*, int> p1;
        pair<TreeNode*, int> p2;
        inorder(root, root, x, 0, p1);
        inorder(root, root, y, 0, p2);
        
        if(p1.first!=p2.first && p1.second==p2.second)
            return true;
            else
               return false;
    }
};