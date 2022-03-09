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

#define lt ListNode
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        lt *curr=head;
        lt *fk=new ListNode(0);
        fk->next=head;
        lt *temp;
        lt *prev=fk;
        
        if(head==NULL || head->next==NULL)
            return head;
        
        while(curr && curr->next)
        {
            if(curr->val==curr->next->val)
            {
               temp=curr->next;
                while(temp && temp->val==curr->val)
                    temp=temp->next;
                prev->next=temp;
                curr=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }  
        }
        return fk->next;
    }
};