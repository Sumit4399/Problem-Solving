class Solution {
public:
    
    int minMoves2(vector<int>& nums) {
        
        int n= nums.size();
        if(n==1)
            return 0;
        
        int steps = 0;
        sort(nums.begin(), nums.end());
        
        int median = nums[n/2]; // Finding median
        for(int i=0; i<n; i++)
        {
            steps += abs(nums[i] - median); 
        }
        return steps;
    }
};