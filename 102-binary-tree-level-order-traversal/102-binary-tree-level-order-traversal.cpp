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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
      while(q.empty()==false)
      {
          vector<int>ans;
          int n=q.size();
          while(n--)
      {
          TreeNode* curr= q.front();
          q.pop();
          ans.push_back(curr->val);
          if(curr->left!=NULL)
          {
              q.push(curr->left);
          }
          if(curr->right!=NULL)
          {
              q.push(curr->right);
          } 
      }
           res.push_back(ans);
      }
      
      return res;
    }
};