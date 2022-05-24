class Solution {
public:
    
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        
        vis[node]= true;
        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(it, adj, vis);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        //base-case
        int edge= connections.size();
        if(edge< n-1)
            return -1;
        
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int c=0; //no.of components
        for(int i=0; i<n; i++)
        {
           if(!vis[i]) 
           {
              dfs(i, adj, vis);
               c++;
           }
        }
        return c-1;
    }
};