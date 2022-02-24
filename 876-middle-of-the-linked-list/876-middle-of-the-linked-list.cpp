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
    ListNode* middleNode(ListNode* head) {
        
        if(!head)
            return head;
        
        //ListNode* temp= head;
        ListNode* slow= head;
        ListNode* fast= head;
        
        while(fast !=  NULL && fast -> next != NULL)
        {
            //temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2  
        }
        
       // temp->next= slow->next;
        return slow;
    }
};