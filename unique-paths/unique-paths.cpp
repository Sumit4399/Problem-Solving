class Solution {
public:
    
    
//     int uniquePaths(int m, int n) {
        
//        int dp[101][101];
//        for(int i = 0;i < n;i++){
//            dp[m - 1][i] = 1;
//        }
//        for(int i = 0;i < m;i++){
//            dp[i][n - 1] = 1;
//        }
//        for(int i = m - 2;i >= 0;i--){
//            for(int j = n - 2;j >= 0;j--){
//                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
//            }
//        }
//        return dp[0][0];
//     }
    
    int uniquePaths(int m, int n){
        
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row > 0)
                {
                    dp[row][col] += dp[row - 1][col];
                }
                if (col > 0) 
                {
                    dp[row][col] += dp[row][col - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    
   // **Combinatorics**
    //     int uniquePaths(int m,int n){
    //     int  N = m + n - 2;
    //     int r = m - 1;
    //     double ans = 1;
    //     for(int i = 1;i <= r;i++){
    //         ans = (ans * (N - r + i))/i;
    //     }
    //     return int(ans);
    // }
};