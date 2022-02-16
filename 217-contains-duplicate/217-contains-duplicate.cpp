class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n= size(nums);
        unordered_set<int> s;
        
        for(int i=0; i<n; i++)
        {
            s.insert(nums[i]);
        }
        
        if(n==s.size())
            return false;
        else
            return true;
    }
};