class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> res;
        
        for(int i=0; i<k; i++)
        {
            res.push_back(nums[i]);
        }
        
        for(int i=k; i<n; i++)
        {
            //int mini= *min_element (res.begin(), res.end());
            int idx = min_element(res.begin(), res.end()) - res.begin();
            if(res[idx] < nums[i])
            {
                res.erase(res.begin()+ idx);
                res.push_back(nums[i]);
            } 
        }
        return res;
    }
};