class Solution {
public:
    
    long long memo(int i, int j, vector<int>& arr, vector<vector<long long>> &dp){
        
        if(i>j)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        //if we take first element
        int first= arr[i] + min(memo(i+2, j, arr, dp), memo(i+1, j-1, arr, dp));
        
        //if we take last element
        int last= arr[j] + min(memo(i+1, j-1, arr, dp), memo(i, j-2, arr, dp));
        
        return dp[i][j]= max(first, last);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n= nums.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        int ans= memo(0, n-1, nums, dp);
        
        int tot= accumulate(nums.begin(), nums.end(), 0);
        
        if(tot-ans <= ans)
            return true;
        else
            return false;
    }
};