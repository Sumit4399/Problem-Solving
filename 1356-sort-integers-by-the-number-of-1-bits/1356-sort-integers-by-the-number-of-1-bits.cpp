class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<int> res;
        //typedef pair<int, int> pi;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<arr.size(); i++)
        {
            int c= __builtin_popcount(arr[i]);
            pq.push({c, arr[i]});
        }
        
        while(!pq.empty())
        {
            int x= pq.top().second;
            res.push_back(x);
            pq.pop();
        }
        return res;
    }
};