class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> s;
        int maxi= 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                s.insert(nums[i]);
                maxi= max(maxi, nums[i]);
            }
        }
        
        for(int i=1; i<=maxi; i++)
        {
            if(s.find(i) == s.end())
            {
                return i;
            }
        }
        
        return maxi+1;
    }
};