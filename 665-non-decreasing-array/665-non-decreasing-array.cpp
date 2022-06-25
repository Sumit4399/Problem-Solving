class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int c=0;
        for(int i=1; i<nums.size() && c<=1; i++)
        {
            if(nums[i-1] > nums[i])
            {
                c++;
                if(i-2<0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];                    
                else 
                    nums[i] = nums[i-1];                               
            }      
        }
        
        if(c<2)
            return true;
        
        return false;
    }
};