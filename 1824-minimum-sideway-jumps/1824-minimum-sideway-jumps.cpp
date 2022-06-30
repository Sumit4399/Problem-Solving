class Solution {
public:
    
    int memo(vector<int>& obs, int pos, int lane, vector<vector<int>> &dp){
        
        int n= obs.size();
        if(pos== n-2)
            return dp[pos][lane]=0;
        
        if(dp[pos][lane] != -1)
            return dp[pos][lane];
        
        if(obs[pos+1] != lane)
            return memo(obs, pos+1, lane, dp);
        
        if(obs[pos+1] == lane)
        {
            int l1, l2;
            if(lane==1)
            {
                l1=2;
                l2=3;
            }
            else if(lane==2)
            {
                l1=1;
                l2=3;
            }
            else
            {
                l1=1;
                l2=2;
            }
            
            if(obs[pos] == l1)
                return dp[pos+1][lane]= 1 + memo(obs, pos+1, l2, dp);
            else if(obs[pos] == l2)
                return dp[pos+1][lane]= 1 + memo(obs, pos+1, l1, dp);
            else
                return dp[pos][lane]= 1+ min(memo(obs, pos+1, l1, dp),
                                             memo(obs, pos+1, l2, dp));
        }
        return dp[pos][lane]= 0;
    }
    
    int minSideJumps(vector<int>& obs) {
        
        int n= obs.size();
        vector<vector<int>> dp(n+1, vector<int> (4,-1));
        return memo(obs, 0, 2, dp);
    }
};