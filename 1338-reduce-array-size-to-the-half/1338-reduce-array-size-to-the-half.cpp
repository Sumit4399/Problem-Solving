class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int half= arr.size();
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto[num, freq] : mp)
        {
            pq.push(freq);
        }
        
        int cnt=0;
        while(!pq.empty())
        {
            int node= pq.top();
            pq.pop();
            
            half= half- node;
            cnt++;
            
            if(half<= arr.size()/2)
                break;
        }
        
        return cnt;
    }
};