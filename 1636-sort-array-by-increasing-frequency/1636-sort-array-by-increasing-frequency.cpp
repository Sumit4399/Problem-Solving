class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> res;
        unordered_map<int, int> mp;
        
        for(int i=0; i<size(nums); i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        
        for(auto it : mp)
        {
            pq.push({-it.second, it.first});
        }
        
        while(!pq.empty())
        {
            int x= pq.top().first;
            for(int i=0; i<abs(x); i++)
            {
                res.push_back(pq.top().second);
            }
            pq.pop();
        }
        return res;
    }
};