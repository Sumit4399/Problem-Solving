class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> res;
        vector<int> v;
        if(size(nums1) >= size(nums2))
        {
            unordered_map<int,int>mp;
            for(auto i : nums1)
            {
                mp[i]++;
            }
            
            for(int i=0; i<size(nums2); i++)
                if (mp[nums2[i]] > 0)
                {
                  mp[nums2[i]]--; 
                  v.push_back(nums2[i]);
                }
        }
        
        else
        {
            unordered_map<int,int>mp;
            for(auto i : nums2)
            {
                mp[i]++;
            }
            
            for(int i=0; i<size(nums1); i++)
                if (mp[nums1[i]] > 0)
                {
                  mp[nums1[i]]--; 
                  v.push_back(nums1[i]);
                }
        }
        
        //res.push_back(v);
        return v;
    }
};