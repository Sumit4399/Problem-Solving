class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n=size(nums);
        
        if(nums[0]<nums[n-1])
        {
            for(int i=0; i<nums.size()-1; i++)
          {
            if(nums[i]<=nums[i+1])
            {
                 continue;
            }
                else
                    return false;
          }
        }
        
        else
        {
            for(int i=0; i<nums.size()-1; i++)
          {
            if(nums[i]>=nums[i+1])
            {
                 continue;
            }
                else
                    return false;
          }
        }
        return true;
    }
};