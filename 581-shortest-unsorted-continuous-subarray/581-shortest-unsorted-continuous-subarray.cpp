class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
//         int n= nums.size();
//         int l=0;
//         int r= n-1;
//         vector<int> v;
        
//         while(l<n)
//         {
//             if(nums[l] < nums[l++])
//                 l++;
//             else
//                 break;
//         }
        
//         // if(l==n)
//         //     return 0;
        
//         while(r>0)
//         {
//             if(nums[r] > nums[r--])
//                 r--;
//             else
//                 break;
//         }
        
//         if(r==0)
//             return 0;
        
//         for(int i=l; i<=r; i++)
//         {
//             v.push_back(nums[i]);
//         }
        
//         return v.size();
        
        
         int ans = 0;  
        
        // Two pointers
        int i = 0;
        int j = nums.size() - 1;

        int curr_max=INT_MAX;
        int curr_min=INT_MIN;
        
        // Initialize end to -1, if we have all sorted in ascending order, then end-start+1 = -1+0+1 = 0 
        int start=0,end=-1;
        
        while(j >= 0){
            // Check if the "num[start]" is greater than the minimum element so far
            if(nums[i] >= curr_min) curr_min = nums[i];
            else end = i; // m contains the 

            // Check if the "num[end]" is less than the maximum element so far
            if(nums[j] <= curr_max) curr_max = nums[j];
            else start = j;

            ++i;
            --j;
        }
        return end - start + 1;
    }
};