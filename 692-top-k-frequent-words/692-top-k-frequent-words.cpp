class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> res;
        unordered_map<string, int> mp;
        for(int i=0; i<size(words); i++)
        {
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>> pq; 
        //vector<int, int>, greater<int, int>>> pq;
        for(auto it : mp)
        {
            pq.push({-it.second, it.first});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        while(k--)
        {
            string x= pq.top().second;
            pq.pop();
            res.push_back(x);
        }
        
        reverse(res.begin(), res.end());
         return res;
    }
};