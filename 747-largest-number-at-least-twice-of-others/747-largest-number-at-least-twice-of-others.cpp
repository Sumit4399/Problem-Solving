class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int count=0;
        int res=0;
        int mx=nums[0];
        for(int i=1; i<size(nums); i++)
        {
            if(mx<nums[i])
            {
                res=i;
                mx=nums[i];
            }
                
        }
        //return res;
        
        for(int i=0; i<size(nums); i++)
        {
            if((i!=res) && (2*nums[i]<=nums[res]))
            {
                count++;
            }
        }
        
        if(count==nums.size()-1)
            return res;
        else
            return -1;
        
    }
};