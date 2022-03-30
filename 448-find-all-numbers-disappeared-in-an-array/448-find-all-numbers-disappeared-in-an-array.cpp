class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        unordered_set<int> s;
        int maxi= INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
            maxi= max(maxi, nums[i]);
        }
        
         for(int i=1; i<=nums.size(); i++)
         {
             if(s.find(i) == s.end())
                 res.push_back(i);
         }
        
//         if(res.size()==0)
//             res.push_back(maxi+1);
        
        return res;
    }
};