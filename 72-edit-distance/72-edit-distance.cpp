class Solution {
public:
    
    //memoised code
//     int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
//         if(j==0)
//             return i;
//         if(i==0)
//             return j;
//        if(dp[i][j] !=-1)
//            return dp[i][j];

//         if(s1[i-1]==s2[j-1])
//             return dp[i][j]= 0 + memo(i-1, j-1, s1, s2, dp);

//         return dp[i][j]=1+ min(memo(i, j-1, s1, s2, dp), 
//                                min(memo(i-1, j, s1, s2, dp), memo(i-1, j-1, s1, s2, dp)));

//     //     int in= 1+ memo(i, j-1, s1, s2); //insert
//     //     int del= 1+ memo(i-1, j, s1, s2); //delete
//     //     int rep= 1+ memo(i-1, j-1, s1, s2); //replace
//     }

//     int minDistance(string s1, string s2) {
//         int n= s1.size();
//         int m= s2.size();
//         vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
//         return memo(n, m, s1, s2, dp);
//     }
    
    
    //tabulation form
    int minDistance(string s1, string s2)
    {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));

        for(int i=0; i<=n; i++)
        {
            dp[i][0]= i;
        }
        for(int j=0; j<=m; j++)
        {
            dp[0][j]= j;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 0 + dp[i-1][j-1];
                else
                    dp[i][j]=1+ min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
    
};