class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
//         int curr_sum=0;// for storing sum of current looping elements
//         int res=INT_MIN;// stores max value after every iteration
        
//         for(int i=0; i<nums.size(); i++)
//         {
//             curr_sum+= nums[i];
//             res= max(res, curr_sum);
//             if(curr_sum<0)
//             {
//                 curr_sum=0;
//             }
//         }
//         return res;
        
        
        //if all the elements in array are negtive
        int maxi= arr[0];
        int curr= arr[0];
        
        for(int i=1; i<size(arr); i++)
        {
            curr= max(arr[i], curr+arr[i]);
            maxi= max(maxi, curr);
        }
        
        return maxi;
        }
};