class Solution {
public:
    
    void dfs(int u, int&count, vector<int>&vis, vector<int>adj[]){  
        
        vis[u]=1;
        for(auto v:adj[u])
        {
            if(vis[abs(v)]!=1)
            {
                if(v>0)
                {
                    count++;
                }
                dfs(abs(v), count, vis, adj);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int count=0;
        vector<int>vis(n, 0);
        vector<int>adj[n];
        
        for(int i=0; i<connections.size(); i++){
            
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        
        for(int i=0; i<n; i++)
        {
            dfs(i, count, vis, adj);
        }
        
        return count;
    }
};