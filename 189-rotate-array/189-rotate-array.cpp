class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // int n=size(nums);
        // k=k%n;
        // while(k>0)
        // {
        //     int temp=nums[n-1];
        //     for(int j=n-2; j>0; j--)
        //     {
        //         nums[j+1]=nums[j];
        //     }
        //     nums[0]=temp;
        // }
        
        int n=size(nums);
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            res[(i + k)%n] = nums[i];
        }
        nums = res;
    }
};