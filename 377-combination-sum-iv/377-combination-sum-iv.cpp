class Solution {
public:
    
    int memo(int tar, vector<int>& nums, vector<int> &dp){
        
      //base case
      if(tar==0)
          return 1;
      if(dp[tar] != -1)
          return dp[tar];
    
        //recursive code
        dp[tar]=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= tar)
            {
                dp[tar]+= memo(tar-nums[i], nums, dp);
            }
        }
        
        return dp[tar];
    }
    
    int combinationSum4(vector<int>& nums, int tar) {
        
        int n=nums.size();
        vector<int> dp(tar+1, -1);
        
        return memo(tar, nums, dp);
    }
};