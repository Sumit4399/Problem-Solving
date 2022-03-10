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
    
    //recursive way
    ListNode* reverseList(ListNode* head){
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*newHead=reverseList(head->next);
        ListNode*restHead= head->next;
        restHead->next=head;
        head->next=NULL;
        return newHead;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ll* list1= reverseList(l1);
        ll* list2= reverseList(l2);
        
        ll *dummy= new ll();
        ll *temp= dummy;
        int carry=0;
        
        while(carry || list1 || list2)
        {
            int sum=0;
            if(list1)
            {
                sum+= list1->val;
                list1=list1->next;
            }
            
            if(list2)
            {
                sum+= list2->val;
                list2= list2->next;
            }
            
            sum+= carry;
            carry= sum/10;
            ll *node= new ll(sum%10);
            temp->next= node;
            temp=temp->next;
        }
        
        return reverseList(dummy->next);
    }
};