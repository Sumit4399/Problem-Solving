class Solution {
public:
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<size(nums); i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq; //vector<int, int>, greater<int, int>>> pq;
        for(auto it : mp)
        {
            pq.push(make_pair(it.second, it.first));
        }
        
        while(k>0)
        {
            int x= pq.top().second;
            pq.pop();
            res.push_back(x);
            k--;
        }
        
        return res;
    }
};