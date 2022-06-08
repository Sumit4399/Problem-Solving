class Solution {
public:
    
    //memoised code
    int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j<0)
            return i+1;
        if(i<0)
            return j+1;
       if(dp[i][j] !=-1)
           return dp[i][j];

        if(s1[i]==s2[j])
            return dp[i][j]= 0 + memo(i-1, j-1, s1, s2, dp);

        return dp[i][j]=1+ min(memo(i, j-1, s1, s2, dp), 
                               min(memo(i-1, j, s1, s2, dp), memo(i-1, j-1, s1, s2, dp)));

    //     int in= 1+ memo(i, j-1, s1, s2); //insert
    //     int del= 1+ memo(i-1, j, s1, s2); //delete
    //     int rep= 1+ memo(i-1, j-1, s1, s2); //replace
    }

    int minDistance(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return memo(n-1, m-1, s1, s2, dp);
    }
};