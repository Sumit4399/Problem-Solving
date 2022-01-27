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
//             else
//             {
                
//             }
//         }
//         return best;
//     }
    
    
    int normalMaximum(vector<int> &nums)//kadane's algorithm
{
    int res=nums[0];
    int maxending=nums[0];
    
    for(int i=1;i<nums.size();i++)
    {
        maxending=max(maxending+nums[i],nums[i]);
        res=max(res,maxending);
    }
    return res;
}
int maxSubarraySumCircular(vector<int>& nums) 
{
    int max_normal=normalMaximum(nums);
    
    if(max_normal<0)//when all elements are -ve
        return max_normal;
    
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];//current array sum
        nums[i]=-nums[i];//inverting the current array
    }
    int maxcircular=sum+normalMaximum(nums);//sum of given array + maximum subarray sum of inverted subarray
    return max(max_normal,maxcircular);
}
};