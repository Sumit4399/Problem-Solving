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
//     TreeNode* invertTree(TreeNode* root) {
//         if(root== NULL)
//             return 0;
//         //vector <int> res;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(q.empty()==false)
//         {
//             TreeNode* curr= q.front();
//             q.pop();
            
//             //res.push_back(curr->val);
            
//             if(curr->left != NULL)
//                 q.push(curr->left);
            
//             if(curr->right != NULL)
//                 q.push(curr->right);
            
//             swap(curr->left,curr->right);
//         }
//         return root;
//    }
    
    TreeNode* invertTree(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        TreeNode* temp= root->left;
        root->left=root->right;
        root->right=temp;
        
        if(root->left!=NULL)
        {
            invertTree(root->left);
        }
        if(root->right!=NULL)
        {
            invertTree(root->right);
        }
        
        return root;
    }
};