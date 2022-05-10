class Solution {
public:
    
    void solve(int start, vector<int>& nums, vector<int> &curr, 
                vector<vector<int>> &res, int target){
    
         if(target==0)
         {
             res.push_back(curr);
             return;
         }
        
         if(target<0)
         {
             return;
         }
        
        for(int i=start; i<nums.size(); i++)
        {
            if(i>start && nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);
            solve(i+1, nums, curr, res, target-nums[i]);
            curr.pop_back(); //back_track
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
            vector<int> curr;
            vector<vector<int>>res;

            solve(0, candidates, curr, res, target);
            return res;
    }
};