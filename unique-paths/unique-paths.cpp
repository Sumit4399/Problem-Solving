class Solution {
public:
    
    
    int uniquePaths(int m, int n) {
        
       int dp[101][101];
       for(int i = 0;i < n;i++){
           dp[m - 1][i] = 1;
       }
       for(int i = 0;i < m;i++){
           dp[i][n - 1] = 1;
       }
       for(int i = m - 2;i >= 0;i--){
           for(int j = n - 2;j >= 0;j--){
               dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
           }
       }
       return dp[0][0];
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