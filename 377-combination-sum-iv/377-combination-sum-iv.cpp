class Solution {
public:
    
    //memoization
//     int memo(int tar, vector<int>& nums, vector<int> &dp){
        
//       //base case
//       if(tar==0)
//           return 1;
//       if(dp[tar] != -1)
//           return dp[tar];
    
//         //recursive code
//         dp[tar]=0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i] <= tar)
//             {
//                 dp[tar]+= memo(tar-nums[i], nums, dp);
//             }
//         }
//         return dp[tar];
//     }
    
    
    //tabulation
    int combinationSum4(vector<int>& nums, int tar) {
        
        int n=nums.size();
        vector<uint> dp(tar+1, 0);
        
        dp[0]=1;
        
        for(int curr=0; curr<=tar; curr++)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] <= curr)
                {
                    dp[curr]+= dp[curr-nums[i]];
                }
            }
        }
        return dp[tar];
    }
};