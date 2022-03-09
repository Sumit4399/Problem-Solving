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
    int pairSum(ListNode* head) {
        
        if(!head)
            return NULL;
        
        unordered_map<int, int> mp;
        vector<int> v;
        int n=0;
        int sum=0;
        
        ListNode* curr=head;
        while(curr)
        {
            n++;
            v.push_back(curr->val);
            curr=curr->next;
        }
        
        for(int i=0; i<=(n/2)-1; i++)
        {
            mp[i]= n-i-1;
        }
        
        for(auto it: mp)
        {
            sum= max(sum, (v[it.first]+ v[it.second]));
        }
        
        return sum;
    }
};