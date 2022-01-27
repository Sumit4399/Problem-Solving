class Solution {
public:
//     int maxSubarraySumCircular(vector<int>& nums) {
        
//         int best=INT_MIN;
//         int curr= nums[0];
//         int n= size(nums);
//         for(int i=1; i<n; i++)
//         {
//             if((nums[i]>curr) && nums[(i + 1) % n]==nums[(i - 1 + n) % n])
//             {
//                 curr= nums[i];
//                 best= max(curr, best);
//             }
//         }
//         return best;
//     }
    
       
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum = max(nums[i],sum+nums[i]);
            ans = max(ans,sum);
        }
        return ans;        
    }
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans_kandane = maxSubArray(nums),total=0;
        
        for(int i=0;i<nums.size();i++)
            total += nums[i],nums[i] = -nums[i];
        int ans_wrap = maxSubArray(nums)+total;
        if(ans_wrap == 0)
            return ans_kandane;
        return max(ans_kandane,ans_wrap);
    }

    
};