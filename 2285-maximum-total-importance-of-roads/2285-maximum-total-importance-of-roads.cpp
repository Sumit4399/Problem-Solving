class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        long long ans=0;
        
        vector<vector<int>> adj(n);
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
        {   
            v.push_back({adj[i].size() , i});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> temp(n);
        int j=1;
        
        for(auto it=v.begin(); it!=v.end()&& j<=n; it++)
        {
            temp[it->second]= j;
            j++;
        }
        
        for(int i=0; i<roads.size(); i++)
        {
            ans+= temp[roads[i][0]] + temp[roads[i][1]];
        }
        return ans;
    }
};