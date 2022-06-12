class Solution {
public:
    
    //Using dp--> O(N*N)
//     int lengthOfLIS(vector<int>& nums) {
        
//         int n=nums.size();
//         if(n==0)
//             return 0;
        
//         vector<int> dp(n,1);
//         int res=1;
        
//         for(int i=1; i<n; i++)
//         {
//             for(int j=0; j<i; j++)
//             {
//                 if(nums[i]>nums[j])
//                 {
//                     dp[i]= max(dp[i], dp[j]+1);
//                 }
//             }
//             res= max(res, dp[i]);
//         }
//         return res;
//     }
    
    
    //Using binary search-->O(NLOGN)
    int lengthOfLIS(vector<int>& nums){
        
        int n= nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int idx= lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[idx]= nums[i];
            }
        }
        return temp.size();
    }
};