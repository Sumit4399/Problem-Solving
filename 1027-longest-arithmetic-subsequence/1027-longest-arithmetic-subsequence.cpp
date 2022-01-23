class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        
        int n=nums.size(), ans=1;
        vector<int> v(1001,0);
        v[0]=1;
        vector<vector<int>> dp(n,v);

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                int diff = nums[i]-nums[j]+500;
                if(dp[j][diff]==0) dp[i][diff]=2;
                else dp[i][diff] = max(dp[i][diff],1+dp[j][diff]);
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
        

         
        //if the array is sorted
//         int n=nums.size();
//         sort(nums.begin(), nums.end());
    
//         if(n<=2)
//             return n;
//         int res=0;
//         int dp[n][n];
//         for(int i=0; i<n; i++)
//             dp[i][n-1]=2;
        
//         for(int j=n-2; j>0; j--)
//         {
//             int i=j-1, k=j+1;
//             while(i>=0 && k<n-1)
//             {
//                if(nums[i]+nums[k] < 2*nums[j])
//                    k++;
//                 else if(nums[i]+nums[k] > 2*nums[j])
//                 {
//                     dp[i][j]=2;
//                     i--;
//                 }
//                 else
//                 {
//                     dp[i][j]= dp[j][k]+1;
//                     res=max(res, dp[i][j]);
//                     i--;
//                     k++;
//                 }
//             }
//             while(i>=0)
//             {
//                 dp[i][j]=2;
//                 i--;
//             }
//         }
//         return res;
//     }
// };