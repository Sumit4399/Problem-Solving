class Solution {
public:
   
      //iterative
//         vector<vector<int>> subsets(vector<int>& nums) {
            
//         vector<vector<int>> ans;
//         int n = nums.size();
        
//         ans.push_back({});
        
//         for(int i=0; i<n; i++)
//         {
//             int sz = ans.size();
//             for(int j=0; j<sz; j++)
//             {
//                 vector<int> temp = ans[j];
//                 temp.push_back(nums[i]);
//                 ans.push_back(temp);
//             }
//         }
//         return ans;
//     }
    
    
        //recursive(back-tracking)
    void solve(int start, vector<int>& nums, vector<int> &curr, 
               vector<vector<int>> &res){
    
        res.push_back(curr);
        
        for(int i=start; i<nums.size(); i++)
        {
            curr.push_back(nums[i]);
            solve(i+1, nums, curr, res);
            curr.pop_back(); //back_track
        }
    }
    
        vector<vector<int>> subsets(vector<int>& nums){
            
            vector<vector<int>> res;
            vector<int> curr;   

            solve(0, nums, curr, res);
            return res;
        }
};