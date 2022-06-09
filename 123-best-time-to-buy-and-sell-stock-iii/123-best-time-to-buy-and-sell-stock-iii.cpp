class Solution {
public:
    
    //memoised form
    int memo(int i, int buy, int cap, vector<int>& val, int n, 
             vector<vector<vector<int>>> &dp)
    {
            int profit=0;
            //base case
            if(cap==0)
                return 0;
            if(i==n)
                return 0;
            if(dp[i][buy][cap] != -1)
                return dp[i][buy][cap];

            if(buy==1)
            {
                profit= max(-val[i] + memo(i+1, 0, cap, val, n, dp), //bought
                            0+ memo(i+1, 1, cap, val, n, dp));       //not bought
            }
            else
            {
                profit= max(val[i] + memo(i+1, 1, cap-1, val, n, dp), //sold
                            0 + memo(i+1, 0, cap, val, n, dp));    //not sold
            }
            return dp[i][buy][cap]= profit;
    }
    
    int maxProfit(vector<int>& val) {
        
        int n= val.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
        return memo(0, 1, 2, val, n, dp);
  }
    
    
    //tabulation form
//     int maxProfit(vector<int>& val) {
//         int n= val.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));

//          for(int i=n-1; i>=0; i--)
//          {
//              for(int buy=0; buy<=1; buy++)
//              {
//                  for(int cap=1; cap<=2; cap++)
//                  {
//                      int profit=0;
//                      if(buy==1)
//                      {
//                          profit= max(-val[i] + dp[i+1][0][cap], //bought
//                                      0+ dp[i+1][1][cap]);       //not bought
//                      }
//                      else
//                      {
//                          profit= max(val[i] + dp[i+1][1][cap-1], //sold
//                                      0 + dp[i+1][0][cap]);    //not sold
//                      }
//                      dp[i][buy][cap]= profit;
//                  }
//              }
//          }
//         return dp[0][1][2];
//     }
    
    
    //space-optimsed
//     int maxProfit(vector<int>& val) {
         
//          int n= val.size();
//          vector<vector<int>> after(2, vector<int> (3,0));
//          vector<vector<int>> curr(2, vector<int> (3,0));

//          for(int i=n-1; i>=0; i--)
//          {
//              for(int buy=0; buy<=1; buy++)
//              {
//                  for(int cap=1; cap<=2; cap++)
//                  {
//                      int profit=0;
//                      if(buy==1)
//                      {
//                          profit= max(-val[i] + after[0][cap], //bought
//                                      0+ after[1][cap]);       //not bought
//                      }
//                      else
//                      {
//                          profit= max(val[i] + after[1][cap-1], //sold
//                                      0 + after[0][cap]);    //not sold
//                      }
//                      curr[buy][cap]= profit;
//                  }
//              }
//              after= curr;
//          }
//         return after[1][2];
//     }
};