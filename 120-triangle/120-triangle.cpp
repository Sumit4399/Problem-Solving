class Solution {
public:
    
//     //memoization
//     int memo(int i, int j, vector<vector<int>>& tri, int n, vector<vector<int>>& dp){
//     //base
//     if(i==n-1)
//         dp[i][j]= tri[n-1][j];
    
//     if(dp[i][j] != INT_MAX)
//         return dp[i][j];
    
//     int d= tri[i][j] + memo(i+1, j, tri, n, dp);
//     int dg= tri[i][j] + memo(i+1, j+1, tri, n, dp);
    
//     return dp[i][j]= min(d, dg);
// }
//     int minimumTotal(vector<vector<int>>& tri) {
        
//         int n= tri.size();
//         vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
//         return memo(0, 0, tri, n, dp);
//     }
    
    
    //tabulation
//     int minimumTotal(vector<vector<int>>& tri){
        
//     int n= tri.size();
//     vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
//     //base case
//     for(int j=0; j<n; j++)
//     {
//         dp[n-1][j]= tri[n-1][j];
//     }
//     for(int i= n-2; i>=0; i--)
//     {
//         for(int j=i; j>=0; j--)
//         {
//             int d= tri[i][j] + dp[i+1][j];
//             int dg= tri[i][j] + dp[i+1][j+1];
//             dp[i][j]= min(d, dg);
//         }
//     }
//     return dp[0][0];
//     }
    
    
    //space-optimsed
    int minimumTotal(vector<vector<int>>& tri){
       
    int n= tri.size();
    vector<int> front(n,0);
    //base case
    for(int j=0; j<n; j++)
    {
        front[j]= tri[n-1][j];
    }
    for(int i= n-2; i>=0; i--)
    {
        vector<int> curr(n,0);
        for(int j=i; j>=0; j--)
        {
            int d= tri[i][j] + front[j];
            int dg= tri[i][j] + front[j+1];
            curr[j]= min(d, dg);
        }
        front= curr;
    }
    return front[0];
    }
};