class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        if(nums.size()==1)
            return 1;
        if(nums.size()==2)
            return 2;
        
        int max_idx=0;
        int min_idx=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]> nums[max_idx])
            {
                max_idx=i;
            }
            
            if(nums[i] < nums[min_idx])
            {
                min_idx=i;
            }
        }
        
        int ans=0;
        int n=nums.size()/2;
//         if(n%2!=0)
//         {
//             n= n/2 +1;
//         }
//         else
//         {
//             n=n/2;
//         }
        
        if(max_idx <=n && min_idx<=n)
        {
            ans= max(max_idx, min_idx) + 1;
        }
        
        else if(max_idx >= n && min_idx>=n)
        {
            ans= nums.size() - min(max_idx, min_idx);
        }
        
        else
        {
            if(max_idx >=n && min_idx <=n)
            {
                // ans+= nums.size()-max_idx;
                // ans+= min_idx+1;
                int a=min_idx+1+(nums.size()-max_idx);
                int b=max_idx+1;
                int c=nums.size()-min_idx;
                ans= min({a,b,c});
            }
            else if(max_idx <=n && min_idx >=n)
            {
                // ans+= nums.size()-min_idx;
                // ans+= max_idx+1;
                int a=max_idx+1+(nums.size()-min_idx);
                int b=min_idx+1;
                int c=nums.size()-max_idx;
                ans= min({a,b,c});
            }
        }
        
        return ans;
    }       
        
        
        
//         if(min_idx<n && max_idx<n){
//             return max(min_idx, max_idx)+1;
//         }
//         else if(min_idx>n && max_idx>n){
//             return nums.size()-min(min_idx, max_idx);
//         }
//         else{
            
//             if(min_idx<max_idx){
//                 return min_idx+1+nums.size()-max_idx;
//             }else{
//                 return max_idx+1+nums.size()-min_idx;
//             }
//         }
//     }
};