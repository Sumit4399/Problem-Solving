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
    
    void preorder(TreeNode* root, unordered_map<int, int> &mp, int &ans){
        
        if(root==NULL)
            return;
        
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL)
        {
            int c=0;
            for(auto it : mp)
                if(it.second%2!=0)
                    c++;
            
            if(c==0 || c==1)
            {
                ans++;
            }
            
            mp[root->val]--;
            return;
        }
        
        preorder(root->left, mp, ans);
        preorder(root->right, mp, ans);
        
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int ans=0;
        unordered_map<int, int> mp;
        
        preorder(root, mp, ans);
        return ans;
    }
};