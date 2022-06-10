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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int rootidx = postorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        return build(inorder, postorder, rootidx, 0, inorder.size()-1, mp);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, 
                    int &rootidx, int left, int right, unordered_map<int, int> &mp){
        
        if(left > right)
            return NULL;
        
        //inorder[pivot]= postorder[rootidx]
        int pivot= mp[postorder[rootidx]];
        TreeNode* node = new TreeNode(inorder[pivot]);
        rootidx--;
        
        node->right= build(inorder, postorder, rootidx, pivot+1, right, mp);
        node->left= build(inorder, postorder, rootidx, left, pivot-1,  mp);
        //rootIdx value gets changed after successive calls to build the left subtree
        //Since it is passed as reference, updated value of rootIdx is passed to build
        //the right subtree
        
        return node;
    }
};