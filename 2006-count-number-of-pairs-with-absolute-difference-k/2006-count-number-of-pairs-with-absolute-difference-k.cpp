class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
    //     //sort(nums.begin(), nums.end());
    //     set<vector<int>> s;
    //     int count=0;
    //     for(int i=0; i<size(nums)-1; i++)
    //     {
    //          for(int j=i+1; j<size(nums); j++)
    //          {
    //              if(abs(nums[i]-nums[j])==k)
    //              {
    //                  //s.insert({nums[i], nums[j]});
    //                  count++;
    //              }
    //          }
    //     }
    //     //count=s.size();
    //     return count;
    // }
        
        
        unordered_map<int, int > freq;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(freq[nums[i]+k])
                {
                    count+=freq[nums[i]+k];
                }
             if(freq[nums[i]-k])
                {
                    count+= freq[nums[i]-k];
                }
            freq[nums[i]]++;
        }
        return count;
    
   }
};