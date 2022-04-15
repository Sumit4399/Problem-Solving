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
    
//     void inorder(TreeNode* root, vector<int> &v)
//     {
//         if (!root) {
//             return;
//         }
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
    
//      TreeNode* trimBST(TreeNode* root, int L, int R){
         
//          vector<int> v;
//          inorder(root, v);
//          vector<int> res;
         
//          for(int i=L; i<=R; i++)
//          {
//              res.push_back(i);
//          }
//      }
    
    
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        
        if (!root) return root;
        
        if (root->val >= L && root->val <= R)
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        
        if (root->val < L)
            return trimBST(root->right, L, R);
        return trimBST(root->left, L, R);
    }
};