class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int i=0, j=0;
        set<int> s;
        int sum=0;
        int res=0;
        
        while(i<n && j<n)
        {
            if(s.find(nums[j]) == s.end())
            {
                sum+= nums[j];
                res= max(res, sum);
                s.insert(nums[j++]);
            }
            else
            {
                sum-= nums[i];
                s.erase(nums[i++]);
            }
        }
        return res;
    }
};