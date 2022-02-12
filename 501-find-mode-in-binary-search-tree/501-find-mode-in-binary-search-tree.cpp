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
    
    void inorder(TreeNode*root, unordered_map<int,int> &mp)
{
    if(!root)
    return;
    
    inorder(root->left, mp);
    mp[root->val]++;
    inorder(root->right, mp);
}
    
    
    vector<int> findMode(TreeNode* root) {
        
        unordered_map<int,int> map;
        inorder(root,map);
        int maxFreq = 0;
        for(auto &i: map)maxFreq = max(i.second,maxFreq);
        vector<int> res;
        for(auto &i: map)
        {
            if(i.second == maxFreq)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};