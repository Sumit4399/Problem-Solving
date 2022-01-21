class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n= nums.size();
        int m= multipliers.size();
        if(m>n) return 0;
        
        int dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        //vector<vector<int>> dp(m+1, vector<int>(m+1,0));
        
        for(int i=m-1; i>=0; i--)
        {
            for(int left=i; left>=0; left--)
            {
                if(i==m)
                    dp[i][left]=0;
                
                else
                {
                    int mul= multipliers[i];
                    int right= (n-1)-(i-left); //if no. is taken from last
                
                //main logic
                dp[i][left]= max(nums[left]*mul + dp[i+1][left+1],  
                                nums[right]*mul + dp[i+1][left]);
                }
                
            }
        }
        
        return dp[0][0];
    }
};