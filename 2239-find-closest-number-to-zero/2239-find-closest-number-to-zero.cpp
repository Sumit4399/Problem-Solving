class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        
//         int neg= -1e5;
//         int pos= 1e5;
        
//         for(int i=0; i<nums.size(); i++)
//         {
//            if(nums[i]>0)
//                pos= min(pos, nums[i]);
            
//             else
//                 neg= max(neg, nums[i]);
//         }
        
//         return (abs(neg)<=pos ? neg : pos);
        
        int mn = INT_MAX;  
        for(auto x:nums)
        {
            if(abs(x)<abs(mn))
                mn = x;
            else if(abs(x)==abs(mn))
                mn = max(x,mn);
        }
        return mn;
    }
};