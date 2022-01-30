class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l=0;
        int h=size(nums)-1;
        int mid;
        
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                h=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};