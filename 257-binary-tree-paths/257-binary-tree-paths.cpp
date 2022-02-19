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
    
    void solve(TreeNode* root, vector<string> &res, string curr)
    {
        if(!root)
            return;
        if(root->left || root->right)
            curr+= (to_string(root->val) + "->");
        else
        {
            curr+= (to_string(root->val));
            res.push_back(curr);
        }
        
        solve(root->left, res, curr);
        solve(root->right, res, curr);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res; 
        string curr="";
        
        solve(root, res, curr);
        return res;
     }
};