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
    int widthOfBinaryTree(TreeNode* root) {
        
//         if(root==NULL)
//         return 0;
//         int res=0;
//         queue<pair<TreeNode*,unsigned long long int>>q;
//         q.push(pair<TreeNode*,unsigned long long int>(root,1));
        
//         while(!q.empty())
//         {
//             int l=q.front().second;
//             int r=l;
//             for(int i=0; i<q.size(); i++)
//             {
//                 TreeNode*curr= q.front().first;
//                 r= q.front().second;
//                 q.pop();
                
//                 if(curr->left !=NULL)
//                 q.push(pair<TreeNode*, unsigned long long int>(curr->left, r*2));
//                 if(curr->right !=NULL)
//                 q.push(pair<TreeNode*, unsigned long long int>(curr->right, r*2+1));
//             }
//             res=max(res, r+1-l);
//         }
//         return res;
        
        if (!root)return 0;
	queue<pair<TreeNode*, unsigned long long int>> que;
	que.push({root, 0});
	int width = 0;
	while (que.size() != 0) {
		unsigned long long int left = que.front().second, right = 0;
		int size = que.size();
		while (size-- > 0) {
			pair<TreeNode*, unsigned long long int> rNode = que.front();
			que.pop();
			right = rNode.second;
			if (rNode.first->left) {
				que.push({rNode.first->left, 2 * rNode.second});
			}
			if (rNode.first->right) {
				que.push({rNode.first->right, 2 * rNode.second + 1});
			}
		}
		width = max(width, int(right - left + 1));
	}
	return width;
    }
};