class Solution {
public:
    //memoised
    int memo(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j] !=-1)
            return dp[i][j];

        int mini= INT_MAX;
        for(int idx=i; idx<=j; idx++)
        {
            int cost= cuts[j+1] - cuts[i-1] + memo(i, idx-1, cuts, dp) +
                memo(idx+1, j, cuts, dp);
            mini= min(mini, cost);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts){
        
        int c= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int> (c+1,-1));
        return memo(1, c, cuts, dp);
    }
    
    
//     int minCost(int n, vector<int>& cuts) {
        
//        int length[n];
//        for(int i=0;i<n;i++){
//            length[i]=i+1;
//        }
//        int t[n+1][n+1];
//        for(int i=0;i<n+1;i++){
//            t[i][0]=0;
//        }
//        for(int i=1;i<n+1;i++){
//            t[0][i]=0;
//        }
//        for(int i=1;i<n+1;i++){
//            for(int j=1;j<n+1;j++){
//                if(length[i-1]<=j){
//                    t[i][j]=min(cuts[i-1]+ t[i][j-length[i-1]],t[i-1][j]);
//                }else{
//                    t[i][j]= t[i-1][j];
//                }
//            }
//        }
//        return t[n][n];
//     }
};