class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>& b){
        
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pair) {
        
        int n= pair.size();
        if(n==1)
            return 1;
        
        sort(pair.begin(), pair.end(), cmp);
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(pair[j][1] < pair[i][0])
                {
                    dp[i]= max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        int ans= *max_element(dp.begin(), dp.end());
        return ans;
    }
};