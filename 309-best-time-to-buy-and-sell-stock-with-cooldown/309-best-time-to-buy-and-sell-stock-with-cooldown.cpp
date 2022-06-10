class Solution {
public:
    
        int memo(int i, int buy, vector<int> &val, int n, vector<vector<int>> &dp)
    {
        int profit=0;
        //base case
        if(i>=n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy==1)
        {
            profit= max(-val[i] + memo(i+1, 0, val, n, dp), //bought
                        0+ memo(i+1, 1, val, n, dp));       //not bought
        }
        else
        {
            profit= max(val[i] + memo(i+2, 1, val, n, dp), //sold
                         0 + memo(i+1, 0, val, n, dp));    //not sold
        }
        return dp[i][buy]= profit;
    }
 
    int maxProfit(vector<int>& val) {
        
        int n= val.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return memo(0, 1, val, n, dp);
    }
};