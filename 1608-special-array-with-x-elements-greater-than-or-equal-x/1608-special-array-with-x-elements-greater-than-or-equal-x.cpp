class Solution {
public:
    
    int solve(vector<int> &nums, int val){
        int c=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>=val)
                c++;
        }
        return c;
    }
    
    int specialArray(vector<int>& nums) {
        
        int l=0;
        int h= 1000;
        
        while(l<=h)
        {
            int mid= (h-l)/2 +l;
            int count= solve(nums, mid);
            
            if(mid== count)
                return count;
            else if(count> mid)
                l++;
            else
                h--;
        }
        return -1;
    }
};