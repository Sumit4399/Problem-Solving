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
//     int count=0;
//     //int res=0;
    
//     int inorder(TreeNode* root, int k) {
        
//         if(root==NULL)
//             return -1;
        
//         else if((count+1)==k)
        
//             return (root->val);
     
//         else if((count+1)>k)
        
//             count++;
//             return inorder(root->left,k);
        
        
//         else if((count+1)<k)
        
//             return inorder(root->right, k-count-1);
        
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
        
//       return inorder(root, k);
//     }
    
    
    void inorder(TreeNode*root, vector<int> &v){
        
        if(root==NULL)
        return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    int kthSmallest(TreeNode* root, int k){
        
        vector<int> v;
        inorder(root, v);
        
        for(int i=0; i<v.size(); i++)
        {
            if(i+1==k)
            {
                return v[i];
            }
        }
        return -1;
    }
};