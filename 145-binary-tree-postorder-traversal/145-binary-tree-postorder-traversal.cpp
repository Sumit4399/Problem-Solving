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
//     vector<int> postorderTraversal(TreeNode* root) {
        
//         stack<TreeNode*> s;
//         vector<int> v;
//         TreeNode* curr= root;
        
//         if(curr==NULL)
//             return v;
        
//         while(curr!=NULL || s.size()!=0)
//         {
//             if(curr!=NULL)
//             {
//                 s.push(curr);
//                 curr=curr->left;
//             }
//             else
//             {
//                 TreeNode*temp= s.top()-> right;
//                 if(temp==NULL)
//                 {
//                     temp=s.top();
//                     s.pop();
//                     v.push_back(temp->val);
                    
//                     while(s.size()!=0 && s.top()->right==temp)
//                     {
//                         temp=s.top();
//                         v.push_back(temp->val);
//                         s.pop();
//                     }
//                 }
//                 else
//                 {
//                     curr=temp;
//                 }
//             }
//         }
        
//         return v;
//     }
    
    void postorder(TreeNode* root, vector<int> &v){
        if(root==NULL)
            return;
        else
        {
            postorder(root->left, v);
            postorder(root->right, v);
            v.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root){
        
        vector<int> v;
        postorder(root,v);
        return v;
    }
};