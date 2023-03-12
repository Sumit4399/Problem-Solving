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
    
    ListNode* merge(ListNode* a,ListNode* b) 
    {
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode* temp=NULL;
        if(a->val<=b->val) 
        {
            temp =a;
            temp->next = merge(a->next,b);
        }
        else 
        {
            temp = b;
            temp->next = merge(a,b->next);
        }
        return temp;        
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        ListNode*res = NULL;
        for(auto i : lists)
        {
            ListNode* temp=NULL;
            res = merge(res, i);
        }
        return res;
    }
};