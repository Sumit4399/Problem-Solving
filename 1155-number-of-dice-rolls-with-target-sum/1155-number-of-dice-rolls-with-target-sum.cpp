class Solution {
public:
    #define mod 1000000007
    
    int memo(int n, int k, int tar, vector<vector<int>> &dp){
        
        if(n==0)
        {
            return tar==0?1:0;
        }
        
        if(dp[n][tar]!=-1)
            return dp[n][tar];
        
        long long int count=0;
        
        for(int i=1 ; i<=k; i++)
        {
            if(tar>=i)
                count = count%mod + memo(n-1, k, tar-i, dp) %mod;
        }
        
        return dp[n][tar]= count%mod;
    }
    
    int numRollsToTarget(int n, int k, int tar) {
        
        vector<vector<int>> dp(n+1, vector<int> (tar+1,-1));
        return memo(n, k, tar, dp);
    }
};