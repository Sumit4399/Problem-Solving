class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++)
        {
            v[i]= {eff[i], sp[i]};
        }
        
        sort(v.rbegin(), v.rend());
        
        long res=0;
        long sum=0;
        
        priority_queue<int, vector<int>, greater<int>> pq;  //min-heap
        
        for(auto[ef, s] : v)
        {
            sum+= s;
            pq.push(s);
            
            while(pq.size()>k)
            {
                sum-= pq.top();
                pq.pop();
            }
            
            res= max(res, ef*sum);
        }
        
        int mod=1e9+7;
        return res%mod;
    }
};