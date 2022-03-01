class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<size(nums); i++)
        {
            pq.push(nums[i]);
        }
        
        int a= pq.top();
        pq.pop();
        a=a-1;
        
        int b= pq.top();
        pq.pop();
        b=b-1;
        
        return a*b;
    }
};