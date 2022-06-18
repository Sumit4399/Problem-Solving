class Solution {
public:
    
    int memo(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        
        if(dp[i][j]!= -1)
            return dp[i][j];
        
        int maxi= INT_MIN;
        for(int idx=i; idx<=j; idx++)
        {
            int coin= nums[i-1] * nums[idx] * nums[j+1] + 
                memo(i, idx-1, nums, dp) + memo(idx+1, j, nums, dp);
            maxi= max(maxi, coin);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return memo(1, n, nums, dp);
    }
};