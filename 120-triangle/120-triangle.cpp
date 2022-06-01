class Solution {
public:
    
    int memo(int i, int j, vector<vector<int>>& tri, int n, vector<vector<int>>& dp){
    //base
    if(i==n-1)
        dp[i][j]= tri[n-1][j];
    
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    
    int d= tri[i][j] + memo(i+1, j, tri, n, dp);
    int dg= tri[i][j] + memo(i+1, j+1, tri, n, dp);
    
    return dp[i][j]= min(d, dg);
}
    
    int minimumTotal(vector<vector<int>>& tri) {
        
        int n= tri.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        return memo(0, 0, tri, n, dp);
    }
};