class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        
        int n= nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int ans= INT_MAX;
        
        while(r<n)
        {
            sum+= nums[r];
            if(sum<tar)
                r++;
            
            else
            {
                while(sum>=tar)
                {
                    sum-= nums[l];
                    ans= min(ans, r-l+1);
                    l++;
                }
                r++;
            }
        }
        
        if(ans== INT_MAX)
            return 0;
        return ans;
    }
};