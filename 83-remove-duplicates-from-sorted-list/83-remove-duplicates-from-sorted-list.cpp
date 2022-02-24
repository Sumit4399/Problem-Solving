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
        lt *temp;
        
        if(curr==NULL)
            return NULL;
        
        while(curr->next!=NULL)
        {
            if(curr->val==curr->next->val)
            {
                temp=curr->next->next;
                curr->next=temp;
            }
            else
            {
                curr=curr->next;
            }
        }
        // while(curr)
        // {
        //     if(curr==temp)
        //    {
        //     curr->next=temp->next;
        //    }
        //     temp=temp->next;
        //     curr=curr->next;
        // }
        lt *help=head;
        return help;
        //return head;
    }
};