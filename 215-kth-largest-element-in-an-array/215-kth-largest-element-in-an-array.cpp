class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        //priority_queue<int, vector<int>, greater<int>>pq;
        //priority_queue<int, vector<int>>pq;
        priority_queue<int>pq;
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
        }
        
        while(k-1 > 0)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
    
};