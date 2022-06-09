class Solution {
public:
//     int maxProfit(int k, vector<int>& prices) {
        
//         int n=prices.size();
//         int dp[n+1][k+1][2];
//         memset(dp,0,sizeof(dp));
//         //vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int>(2,0)));
        
//         for(int i=n-1; i>=0; i--)
//         {
//             for(int rem=1; rem<=k; rem++)
//             {
//                 for(int hold=0; hold<2; hold++)
//                 {
//                     int no= dp[i+1][rem][hold];
//                     int yes;
//                     if(hold==1) //selling stock
//                     {
//                         yes= prices[i] + dp[i+1][rem-1][0];
//                     }
//                     else //(hold==0) buying stock
//                     {
//                         yes= -prices[i] + dp[i+1][rem][1];
//                     }
//                     //recurrence relation
//                     dp[i][rem][hold]= max(no, yes);
//                 }
//             }
//         }
        
//         return dp[0][k][0];
//     }
    
    
    int memo(int i, int tran, int k, int n, vector<int> &pri, vector<vector<int>> &dp)
        {
            if(i==n || tran== 2*k)
                return 0;
            if(dp[i][tran] != -1)
                return dp[i][tran];

            if(tran%2==0) //buy
            {
                return dp[i][tran]= max(-pri[i] + memo(i+1, tran+1, k, n, pri, dp),
                                       0+ memo(i+1, tran, k, n, pri, dp));
            } //sell
                return dp[i][tran] = max(pri[i] + memo(i+1, tran+1, k, n, pri, dp),
                                       0+ memo(i+1, tran, k, n, pri, dp)); 
        }
    
        int maxProfit(int k, vector<int>& pri){
            
            int n= pri.size();
            vector<vector<int>> dp(n, vector<int> (2*k, -1));
            return memo(0, 0, k, n, pri, dp);
        }
};