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
    
//     vector<int> v;
//     void inorder(TreeNode* root)
//     {
//         if (!root) {
//             return;
//         }
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
    
//     bool isValidBST(TreeNode* root) {
        
//         inorder(root);
//         if (root==NULL)
//             return true;
//         for (int i = 0; i < v.size() - 1; i++) {
            
//             if (v[i] >= v[i + 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
    bool isValidBST(TreeNode* root) {
        
        return help(root, LONG_MIN, LONG_MAX);
    }
    
    bool help(TreeNode* root, long min, long max){
        
        if(!root)   return true;
        if(root->val <= min || root->val >= max)  return false;
        
        return help(root->left, min, root->val) && help(root->right, root->val, max);
    }
};