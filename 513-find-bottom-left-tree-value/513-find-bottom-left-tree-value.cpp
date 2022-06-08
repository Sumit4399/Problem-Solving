/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;3
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        //level order traversal
        if(root==NULL) return -1;
        if(root->left==NULL && root->right==NULL) return root->val;
        int res=(root->left!=NULL)?root->left->val:root->right->val;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        
        while (!q.empty())
        {
            for (int i = q.size() - 1, flag=false; i >= 0; --i) 
            {
                TreeNode* curr = q.front(); q.pop();
                
                if(curr->left!=NULL && flag==false){
                    flag=true;
                    res=curr->left->val;
                    q.push(curr->left);
                }
                else if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->left==NULL && curr->right!=NULL && flag==false){
                    flag=true;
                    res=curr->right->val;
                    q.push(curr->right);
                }
                else if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        return res;
        
//         while (q.size())
//         {
//             for (i = q.size() - 1, res = 0; i >= 0; --i) 
//             {
//                 TreeNode* node = q.front(); q.pop();
//                 res = node->val;
                
//                 if(node->left==NULL && node->right==NULL)
//                 {
//                     q.empty();
//                     break;
//                 }
//                 if (node->right) q.push(node->right);
//                 if (node->left)  q.push(node->left);
                
//             }
//         }
//         return res;
    }
};