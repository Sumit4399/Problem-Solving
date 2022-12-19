class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edg, int src, int dest) {
        
        vector<vector<int>> adj(n);
        for(auto it : edg)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(src);
        vis[src]= true;
        
        while(!q.empty())
        {
            int curr= q.front();
            q.pop();
            
            if(curr==dest)
                return true;
            
            for(auto &node: adj[curr])
            {
                if(!vis[node])
                {
                    vis[node]= true;
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};