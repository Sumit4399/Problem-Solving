class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int prefix=0;
        int res=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int val;
            
            if(nums[i] == 0)
                val = -1;
            
            else
                val = 1;
       
       
            prefix+= val;
            if(prefix==0)
            {
                res= i+1;
            }
            
            if(mp.find(prefix)== mp.end());
            mp.insert({prefix, i});
            
            if(mp.find(prefix)!= mp.end())
            res= max(res, i-mp[prefix]);
        }
        return res;
    }
};