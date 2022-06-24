class Solution {
public:
    
    //find the left-half using binary search and low will point to single element
    // right-half
    //     1st instance= odd index
    //     2nd instance= even index
    
    // left-half
    //     1st instance= even index
    //     2nd instance= odd index
    
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high= n-2; //because if the single element lies at last position
        
        while(high>=low)
        {
            int mid= (high + low)/2;
            if(nums[mid] == nums[mid^1])
                low= mid+1;
            else
                high= mid-1;
        }
        return nums[low];
    }
};