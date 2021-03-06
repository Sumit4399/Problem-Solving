class Solution {
public:

    int numTrees(int n) {
       
        //recursive
//         int result=0;
//         if(n==1 || n==0)
//             return 1;
//         for(int i=0;i<n;i++)
//             result+=numTrees(i)*numTrees(n-i-1);
//         return result;
          
        
        int dp[20];
        memset(dp,0, sizeof(dp));
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                dp[i]=dp[i]+ dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
        
    }
};