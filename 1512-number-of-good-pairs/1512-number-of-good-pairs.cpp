class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        // int res=0;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=0; j<nums.size(); j++)
        //     {
        //         if(i<j && nums[i]==nums[j])
        //         {
        //             res++;
        //         }
        //     }
        // }
        // return res;
        
        int res=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it: mp)
        {
            int n= it.second;
            res+= (n*(n-1))/2;
        }
        return res;
    }
};