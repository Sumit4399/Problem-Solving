class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int res=INT_MIN;
        unordered_set<int> s;
        
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(i) == s.end())
                res= i;
        }
        
        if(res==INT_MIN)
            return nums.size();
        else
            return res;
    }
};