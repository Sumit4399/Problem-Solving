class Solution {
public:
    
    void solve(int index, vector<int> nums, vector<vector<int>> &res){
        
         if(index== nums.size())
        {
            res.push_back(nums);
        }
        
        for (int i = index; i < size(nums); ++i)
        {
            if (i != index && nums[i] == nums[index])
                continue;
            
            swap(nums[i], nums[index]);
            solve(index+1, nums, res);
        }
        
        // // restore nums
        // for (int i = nums.size() - 1; i > index; --i) 
        // {
        //     swap(nums[index], nums[i]);
        // }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        solve(0, nums, res);
        
        cout<<res.size()<<endl;
        return res;
    }
};