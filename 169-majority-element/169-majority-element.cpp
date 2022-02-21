class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int res=0;
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        
        for(auto e: mp)
            if(e.second > n/2)
            {
                res=e.first;
            }
        return res;
    }
};