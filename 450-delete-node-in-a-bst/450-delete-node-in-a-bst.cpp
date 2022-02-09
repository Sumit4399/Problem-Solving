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
    
    TreeNode* findmin(TreeNode* root){
        if(root->left== NULL)
            return root;
        return findmin(root->left);
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        else if(key > root->val)
            root->right= deleteNode(root->right, key);
        
        else if(key < root->val)
            root->left= deleteNode(root->left, key);
        //till here we search the key in tree
        
        else
        {
            //if root has no child
            if(root->left==NULL && root->right==NULL)
            {
                //TreeNode* temp= root;
                delete(root);
                //root=NULL;
                return NULL;
            }
            
            //case when 1 child is present
            else if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* temp= root;
                root= root->right;
                delete(temp);
                return root;
            }
            
            else if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* temp= root;
                root= root->left;
                delete(temp);
                return root;
            }
            
            //case when both elements are present
            else
            {
                TreeNode*temp= findmin(root->right);
                root->val= temp->val;
                root->right= deleteNode(root->right, root->val);
            }
        }
        
        return root;
    }
};