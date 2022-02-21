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
    
    void find(TreeNode* root, int targetSum, int sum, bool elementTaken, int &c){
        if(elementTaken && sum==targetSum){
            // for(int i=0;i<temp.size();i++) {
            //     cout<<temp[i]<<" "<<sum<<" "<<targetSum<<" ";
            // }
            // cout<<"\n";
            c++;
        }
        
        if(root==NULL) {
            return;
        }
        
       // vector<int> newTemp;
        if(root->left)
        {
            if(elementTaken==false)
                find(root->left, targetSum,0, false,  c);
            // temp.push_back(root->left->val);
             find(root->left, targetSum, sum+root->left->val, true, c);
            // temp.pop_back();
        }
        
        if(root->right)
        {
            if(elementTaken==false)
                find(root->right, targetSum,0, false,  c);
            // temp.push_back(root->right->val);
            // cout<<root->val<<" "<<root->right->val<<" "<<sum<<"\n";
             find(root->right, targetSum, sum+root->right->val, true,  c);
            // temp.pop_back();
        }
          
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) {
            return 0;
        }
        int c=0;
        //int sum=0;
        vector<int> temp;
        find(root, targetSum, 0, false, c);
        // temp.push_back(root->val);
        find(root, targetSum, root->val, true, c);
        return c;
    }
};