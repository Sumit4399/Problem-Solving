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
    
    // void inorder(TreeNode* root, vector<int> &v)
    // {
    //     if(!root)
    //         return;
    //     inorder(root->left, v);
    //     v.push_back(root->val);
    //     inorder(root->right, v);
    // }
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> v;

        function<void(TreeNode*)> inorder = [&](TreeNode* root2)
        {
            if(!root2)
            return;
            inorder(root2->left);
            v.push_back(root2->val);
            inorder(root2->right);
        };
        // TreeNode* temp = root;
        inorder(root);
        int res= INT_MAX;
        for(int i=1; i<size(v); i++)
        {
            res=min(res, abs(v[i]-v[i-1]));
        }
        return res;
    }
};