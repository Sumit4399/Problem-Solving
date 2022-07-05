class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
//         if(nums.size()==1)
//             return 1;
        
//         unordered_set<int> s1;
//         for(int i=0; i<nums.size(); i++)
//         {
//             s1.insert(nums[i]);
//         }
        
//         unordered_set<int> s2;
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(s1.find(nums[i]-1) != s1.end())
//                 s2.insert(nums[i]);
            
//             else if(s1.find(nums[i]+1) != s1.end())
//                 s2.insert(nums[i]);
            
//             else
//                 s1.erase(nums[i]);
//         }
//         return s2.size();
        
        
        //insert all elements in set
        unordered_set<int> mp(begin(nums), end(nums));
        int longest = 0;
        
        for(auto& num : mp)
        {
            if(mp.count(num - 1)) 
                continue;
            
            int j = 1;
            while(mp.count(num + j)) 
                j++;
            
            longest = max(longest, j);
        }
        
        return longest;
    }
};