class Solution {
public:
    
//     //tabulation form
//     int lcs(string s, string t)
//     {
//         int n= s.size();
//         int m= t.size();
//         vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

//         for(int i=0; i<=n; i++)
//             dp[i][0]=0;
//         for(int j=0; j<=m; j++)
//             dp[0][j]=0;

//         for(int i=1; i<=n; i++)
//         {
//             for(int j=1; j<=m; j++)
//             {
//                 //match
//                 if(s[i-1] == t[j-1])
//                     dp[i][j]= 1+ dp[i-1][j-1];

//                 //not match
//                 else
//                     dp[i][j]= 0 + max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[n][m];                            
//     }

//     int longestPalindromeSubsequence(string s)
//     {
//         string t=s;
//         reverse(t.begin(), t.end());
//         return lcs(s, t);
//     }
    
    bool isPalindrome(string s){
        
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1]) 
            return false;
    }
    return true;
}
    
    int removePalindromeSub(string s) {
        
        if(s.size()==0)
            return 0;
        if(isPalindrome(s) == true)
            return 1;
        else
            return 2;
    }
};