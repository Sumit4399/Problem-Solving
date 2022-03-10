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

#define ll ListNode
class Solution {
public:
    
//    ListNode* reverseList(ListNode* head){
        
//         if(head==NULL || head->next==NULL)
//             return head;
        
//         ListNode*newHead=reverseList(head->next);
//         ListNode*restHead= head->next;
//         restHead->next=head;
//         head->next=NULL;
//         return newHead;
        
//     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ll *dummy= new ll();
        ll *temp= dummy;
        int carry=0;
        
        while(carry || l1 || l2)
        {
            int sum=0;
            if(l1)
            {
                sum+= l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+= l2->val;
                l2=l2->next;
            }
            
            sum+= carry;
            carry= sum/10;
            ll *node= new ll(sum%10);
            temp->next= node;
            temp=temp->next;
        }
        
        return dummy->next;
    }
};