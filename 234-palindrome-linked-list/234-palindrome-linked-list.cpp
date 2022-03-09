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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(!head)
            return NULL;
        
        vector<int> v;
        int n=0;
        
        ListNode* curr=head;
        while(curr)
        {
            n++;
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        int i=0; 
        int j= v.size()-1;
        
        while(i<=j)
        {
            if(v[i++]!=v[j--])
            {
                return false;
            }
        }
        
        return true;
    }
};