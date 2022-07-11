class Solution {
public:
    
    int memo(int i, vector<int>& nums, vector<int>& dp){
        
        if(i>=nums.size()-1)
            return 0;
        
        if(dp[i] != 10001)
            return dp[i];
        
        for(int j=1; j<= nums[i]; j++)
        {
            dp[i]= min(dp[i], 1+ memo(i+j, nums, dp));
        }
        
        return dp[i];
    }
    
    int jump(vector<int>& nums) {
        
        int res=0;
        vector<int> dp(nums.size(), 10001);
        return memo(0, nums, dp);
    }
};