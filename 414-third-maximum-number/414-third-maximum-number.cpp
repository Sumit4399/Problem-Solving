class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        
        if(st.size()<3)
            return *max_element(nums.begin(), nums.end());
        
        priority_queue<int> pq;
        for(auto it= st.begin(); it!=st.end(); it++)
        {
            pq.push(*it);
        }
        
        int k=3;
        while(k-1>0)
        {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};