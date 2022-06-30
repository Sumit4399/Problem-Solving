class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1)
            return {0};
        
        vector<int> res;
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(degree[i]==1)
                q.push(i);
        }
        
        while(!q.empty())
        {
            res.clear();
            int size= q.size();
            for(int i=0; i<size; i++)
            {
                int curr= q.front();
                q.pop();
                res.push_back(curr);
                
                for(auto it : adj[curr])
                {
                    degree[it]--;
                    if(degree[it]==1)
                        q.push(it);
                }
            }  
        }
        return res;
    }
};