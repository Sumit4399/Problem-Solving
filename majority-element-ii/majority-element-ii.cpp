class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> res;
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        
        for(auto e: mp)
            if(e.second > n/3)
            {
                res.push_back(e.first);
            }
        return res;
    }
};