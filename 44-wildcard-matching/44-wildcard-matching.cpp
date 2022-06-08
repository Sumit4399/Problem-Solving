class Solution {
public:
    
    //memoization
//         bool memo(int i, int j, string &pat, string &t, vector<vector<bool>> &dp){
//         //base case
//         if(i<0 && j<0)
//             return true;
//         if(i<0 && j>=0)
//             return false;
//         if(i>=0 && j<0)
//         {
//             for(int k=i; k>=0; k--)
//             {
//                 if(pat[k]!= '*')
//                     return false;
//             }
//             return true;
//         }
//         if(dp[i][j] != false)
//             return dp[i][j];

//         if(pat[i] == t[j] || pat[i]== '?') //match
//             return dp[i][j] = memo(i-1, j-1, pat, t, dp);
//         if(pat[i] == '*') //taking and not taking '*'
//             return dp[i][j] = memo(i-1, j, pat, t, dp) or memo(i, j-1, pat, t, dp);
//         return dp[i][j] = false;
//     }

   
    //tabualtion approach
    bool isMatch(string s, string p) {
        
        int n= s.size();
        int m= p.size();
        vector<vector<bool>> dp(n + 1, vector(m + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < m && p[j] == '*'; ++j) 
        {
            dp[0][j + 1] = true;
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= m; ++j) 
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } 
                else 
                {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }
    
};