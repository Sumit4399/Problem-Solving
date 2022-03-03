class Solution {
public:
    
    int solve(vector<int>& nums, int res)
    {
        vector<int> dp(nums.size());
        for (int i = 2; i < dp.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = 1 + dp[i - 1];
                res += dp[i];
            }
        }
        return res;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
       
        int res=0;
        return solve(nums,res);
    }
};