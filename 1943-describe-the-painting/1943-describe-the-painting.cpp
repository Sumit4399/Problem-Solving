class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        
        map<int, long long> d;
        for (auto& a : seg) 
        {
            d[a[0]] += a[2];
            d[a[1]] -= a[2];
        }
        
        vector<vector<long long> > res;
        int i = 0;
        for (auto& it : d)
        {
            if (d[i] > 0)
                res.push_back({i, it.first, d[i]});
            d[it.first] += d[i];
            i = it.first;
        }
        
        return res;
    }
};