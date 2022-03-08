/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define lt ListNode
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        lt *slow=head;
        lt *fast=head;
        
        while(slow!= NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
    }
};