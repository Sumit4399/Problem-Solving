class Solution {
public:
    
    long long int memo(int n, vector<long long int> &dp){
        
        if(n==1)
            return dp[n]= 2;
        if(n==2)
            return dp[n]= 3;
        if(dp[n]!= -1)
            return dp[n];
        
        long long int pick, not_pick, mod= 1e9+7;
        
        pick= memo(n-2, dp)%mod;
        not_pick = memo(n-1, dp)%mod;
        
        return dp[n]= (pick + not_pick)%mod;
    }
    
    int countHousePlacements(int n) {
        
        vector<long long int> dp(n+1, -1);
        memo(n, dp);
        
        long long int mod= 1e9+7;
        return (dp[n]*dp[n])%mod;
    }
};