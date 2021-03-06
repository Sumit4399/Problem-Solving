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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode* dummy=new ListNode();
    ListNode* p=dummy;
    while(l1!=NULL && l2!=NULL){
        if(l1->val<=l2->val){
            p->next=l1;
            l1=l1->next;
        }
        else{
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    p->next=(l1!=NULL) ? l1 : l2;
    return dummy->next;
}
};