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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(!head || !head->next)
            return head;
        int res=k;
        
        //finding kth element from front
        ListNode* temp1= head;
        while(k>1)
        {
            temp1=temp1->next;
            k--;
        }
        
        //counting total element in linked list
        ListNode* temp2=head;
        int count=1;
        while(temp2)
        {
            temp2=temp2->next;
            count++;
        }
        
        //finding kth element from end
        ListNode* temp3=head;
        int end= count-res;
        while(end>1 && temp3->next)
        {
            temp3= temp3->next;
            end--;
        }
        
        swap(temp1->val, temp3->val);
        return head;
    }
};