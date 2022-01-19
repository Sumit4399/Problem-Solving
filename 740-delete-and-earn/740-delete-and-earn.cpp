class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=10001;
       
        vector<int> mp(n,0);
        for(auto i: nums)
        {
        mp[i] += i;
        }
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = mp[1];
        
        //now apply the house robbing concept
        for(int i=2; i<n; i++)
        {
        dp[i] = max(dp[i-2] + mp[i], dp[i-1]);
        }
    
       return dp[n-1];
    }
};