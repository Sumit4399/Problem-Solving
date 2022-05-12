class Solution {
public:
    
    void findrecur(int index, vector<int>& nums, vector<vector<int>> &res){
        
        if(index== nums.size())
        {
            res.push_back(nums);
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            findrecur(index+1, nums, res);
            swap(nums[index], nums[i]); //back-track
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        findrecur(0, nums, res);
        return res;
    }
};