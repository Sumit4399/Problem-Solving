/**

Today we have drink vodka and we mean Atishay patni,Sushant verma,Avinash Kumar and our dearest friend Sumit Anand.We have meet after          years and we are happy that such a great moment we have got to share but we are missing ours rest of our T.Y.I.C member that they are not with us.we are greatful we have got such a moment to share our feelings after a great time.At last i would like to rest my words...........
            Avinash Kumar 2K19,Chemical Engineering
            
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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode * dummy=new ListNode(NULL);
        ListNode * temp=dummy;
        head=head->next;
        int sum=0;
        while(head)
        {
            if(head->val!=0)
                sum+=head->val;
            else
            {
                temp->next=new ListNode(sum);
                temp=temp->next;
                sum=0;
            }
            head=head->next;
        }
        return dummy->next;
    }  
};