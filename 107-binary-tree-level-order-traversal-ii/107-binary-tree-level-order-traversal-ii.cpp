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
       
        int height(TreeNode* node)
    {
        if (node == NULL)
            return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

    void printCurrentLevel(TreeNode* root, int level, vector<int>& res)
    {
        if (root == NULL)
            return;
        if (level == 1)
            res.push_back(root->val);
        else if (level > 1) {
            printCurrentLevel(root->left, level - 1, res);
            printCurrentLevel(root->right, level - 1, res);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        int i;
        vector<vector<int>> res;
        for (i = 1; i <= h; i++){
            vector<int> temp;
            printCurrentLevel(root, i, temp);
            res.push_back(temp);
        }
        vector<vector<int>> ans;
        for(int i = res.size()-1;i>=0;i--) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};