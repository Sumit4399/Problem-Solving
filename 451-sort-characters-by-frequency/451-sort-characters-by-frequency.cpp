class Solution {
public:
    string frequencySort(string s) {
        
        string res="";
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty())
        {
            int x= pq.top().first;
            // cout<<x<<"\n";
            for(int i=0; i<x; i++)
            {
                res.push_back(pq.top().second);
                //res+=pq.top().second;
            }
            pq.pop();
        }
        
        return res;
    }
};