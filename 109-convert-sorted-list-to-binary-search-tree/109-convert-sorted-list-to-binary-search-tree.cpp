/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* build(vector<int>& nums, int low, int high)
    {
        if(low<=high)
        {
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(nums, low, mid-1);
            root->right = build(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
       
        // if(!head)
        //     return TreeNode*(head);
        vector<int> v;
        ListNode* temp= head;
        while(temp)
        {
            v.push_back(temp->val);
            temp= temp->next;
        }
        
        return build(v, 0, size(v)-1);
    }
};