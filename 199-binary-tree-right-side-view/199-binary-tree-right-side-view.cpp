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
//     vector<int> rightSideView(TreeNode* root) {
        
//         vector<int> res;
//         if(root==NULL)
//             return res;
//         queue<TreeNode*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int n= q.size();
//             for(int i=0; i<n; i++)
//             {
//                 TreeNode* curr=q.front();
//                 q.pop();
//                 if(i==0)
//                 {
//                     res.push_back(curr->val);
//                 }
//             }
//             if(root->left!=NULL)
//                 q.push(root->left);
//             if(root->right!=NULL)
//                 q.push(root->right);
//         }
//         return res;
//     }
    
    void level(TreeNode *root,int lev,vector<int> &v)
    {
    if(root==NULL) return;
    if(v.size()==lev) v.push_back(root->val);
    level(root->right,lev+1,v);
    level(root->left,lev+1,v);
   }
     
      vector<int> rightSideView(TreeNode* root){
          
          vector<int> res;
          level(root,0,res);
          return res;
      }
};