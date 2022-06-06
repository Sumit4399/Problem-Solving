/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        if(headA==NULL || headB==NULL)
            return NULL;
       //using SET
       unordered_set<ListNode*> s;
        ListNode * t= headA;
      while(t!=NULL)
      {
          s.insert(t);
          t= t->next;
      }
		
        t= headB;
        while(t!=NULL)
        {
            if(s.find(t) != s.end())
                return t;
            
            t= t->next;
        }
          return NULL;  
    }
};