class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int n= nums.size();
        if(k==0)
        {
            if(n>=1)
                return nums[0];
            else
                return -1;
        }
        
        if(k==1)
        {
            if(n>=2)
                return nums[1];
            else
                return -1;
        }
        
        if(n==1)
        {
            if(k%2)
                return -1;
            else
                return nums[0];
        }
        
        int res=0;
        for(int i=0; i<min(k-1, n); i++)
        {
            res= max(res, nums[i]);
        }
        
        if(k<n)
        {
            res= max(res, nums[k]);
        }
        
        return res;
    }
};