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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         if(!head)
//             return NULL;
        
//         //count the size pof linked list
//         int c=1;
//         ListNode* temp= head;
//         while(temp)
//         {
//             temp= temp->next;
//             c++;
//         }
        
//         //finding the element to be deleted
//          if(c==1 && n==1)
//          {
//             delete(head);
//             return NULL;
//          }
        
//         else if(c==n)
//         {
//            ListNode* curr=head;
//             head=head->next;
//             delete(curr);
//             return head;
//         }
        
//         else
//         {
//             ListNode*first =head;
//         for(int i=1; i<c-n && n<c; i++){
//             first=first->next;
//         }
            
//        ListNode *temp= first->next;
//         first->next=temp->next;
//         delete(temp);
//         return head;
//         }
        
         if(head==NULL){
            return NULL;
        }
        
        
        ListNode *first=head;
        
        int len=0;

        while(first!=NULL){
            len++;
            first=first->next;
        }
        if(len==1 && n==1){
            delete(head);
            return NULL;
        }
        else if(len==n){
           ListNode* curr=head;
            head=head->next;
            delete(curr);
            return head;
        }
        else{
            first=head;
        for(int i=1; i<len-n && n<len; i++){
            first=first->next;
        }
       ListNode *temp= first->next;
        first->next=temp->next;
        delete(temp);
        return head;
        
        }
    }
};