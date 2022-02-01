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

//#include <math.h>
class Solution {
public:
//     int countNodes(TreeNode* root) {
        
//         int lh=0, rh=0;
//         TreeNode* curr=root;
        
//         while(curr!=NULL)
//         {
//             lh++;
//             curr=curr->left;
//         }
        
//         while(curr!=NULL)
//         {
//             rh++;
//             curr=curr->right;
//         }
        
//         if(lh==rh)
//         {
//             return pow(2,rh)-1;
//         }
        
//         return 1+ countNodes(root->left) + countNodes(root->right);
//     }
    
    
       int countNodes(TreeNode* root){
           
           if(root==NULL)
               return 0;
           else
               return 1+countNodes(root->left)+countNodes(root->right);
       }
};