class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double mx=INT_MIN;
        long long sum=0;
        int i=0, j=0, n=nums.size();
        
        while(j<n && i<n){
            if((j-i)+1==k){
                sum+=nums[j];
                mx=max(mx, (double)sum/k);
                sum-=nums[i];
                i++;
                j++;
            }else{
                sum+=nums[j];
                j++;
            }
        }
        
        return mx;
    }
};