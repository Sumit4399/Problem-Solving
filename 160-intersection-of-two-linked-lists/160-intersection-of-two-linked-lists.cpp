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
        
        
//         if(headA==NULL || headB==NULL)
//             return NULL;
//        //using SET
//        unordered_set<ListNode*> s;
//         ListNode * t= headA;
//           while(t!=NULL)
//           {
//               s.insert(t);
//               t= t->next;
//           }

//         t= headB;
//         while(t!=NULL)
//         {
//             if(s.find(t) != s.end())
//                 return t;
            
//             t= t->next;
//         }
//           return NULL;  
     
        
        
        //efficient approach
        if(headA==NULL || headB==NULL)
            return NULL;
        
        ListNode * l1= headA;
        ListNode * l2= headB;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1==l2)
                return l1;
            
            else if(l1->next==NULL && l2!=NULL)
            {
                l1=headB;
                l2= l2->next;
            }
            
            else if(l2->next==NULL && l1!=NULL)
            {
                l2=headA;
                l1= l1->next;
            }
            
            else
            {
                l1= l1->next;
                l2= l2->next;
            }
        }
        
        return NULL;
    }      
};