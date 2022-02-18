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
    
//     int sumOfLeftLeaves(TreeNode* root) {
        
//         int ans=0;
//         vector<int> v;
//         if(root)
//         {
//             if(root->left && !root->left->left && !root->left->right)
//             {
//                 ans= root->left->val;
//                 v.push_back(ans);
//             }
//             sumOfLeftLeaves(root->left);
//             sumOfLeftLeaves(root->right);
//         }
        
//         int temp=0;
//         for(int i=0; i<size(v); i++)
//         {
//            temp+= v[i]; 
//         }
//         return temp;
        
        int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left && !root->left->right && !root->left->left)
            return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->right)+sumOfLeftLeaves(root->left);
    }
};