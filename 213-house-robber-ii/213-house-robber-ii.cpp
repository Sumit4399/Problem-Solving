class Solution {
public:
    
    int memo(vector<int>& nums,int i, int n, vector<int>& dp){
        
       if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int pick= nums[i]+ memo(nums,i+2,n,dp);
        int not_pick= memo(nums,i+1,n,dp);
        
        return dp[i]= max(pick, not_pick);
    }
    
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> dp1(n,-1);
        int ans1= memo(nums, 0, n-1, dp1);
        
        vector<int> dp2(n,-1);
        int ans2= memo(nums, 1, n, dp2);
        
        return max(ans1,ans2);
    }
};