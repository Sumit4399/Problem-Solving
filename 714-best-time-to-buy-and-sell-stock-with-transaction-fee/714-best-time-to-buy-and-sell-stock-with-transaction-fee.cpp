class Solution {
public:
    
    //memoised code
    int memo(int i, int buy, int fee, int n, vector<int>& pri, vector<vector<int>> &dp){
        
        //base base
        if(i==n)
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int profit=0;
        if(buy==1)
        {
                            //buy                                      //not-buy
            profit= max(-pri[i] + memo(i+1, 0, fee, n, pri, dp), memo(i+1, 1, fee, n, pri, dp));
        }
        else
        {
                            //sold                                  //not-sold
            profit= max(pri[i]-fee + memo(i+1, 1, fee, n, pri, dp), memo(i+1, 0, fee, n, pri, dp));
        }
        return dp[i][buy]= profit;
    }
    
    int maxProfit(vector<int>& pri, int fee) {
        int n= pri.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return memo(0, 1, fee, n, pri, dp);
    }
};