class Solution {
public:
    
//     void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        
//         vis[node]= true;
//         for(auto it : adj[node])
//         {
//             if(!vis[it])
//                 dfs(it, adj, vis);
//         }
//     }
    
//     int makeConnected(int n, vector<vector<int>>& connections) {
        
//         //base-case
//         int edge= connections.size();
//         if(edge< n-1)
//             return -1;
        
//         vector<bool> vis(n, false);
//         vector<vector<int>> adj(n);
//         for(auto it : connections)
//         {
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
        
//         int c=0; //no.of components
//         for(int i=0; i<n; i++)
//         {
//            if(!vis[i]) 
//            {
//               dfs(i, adj, vis);
//                c++;
//            }
//         }
//         return c-1;
//     }
    
    
    //using union-find
   //  vector<int>parent;
    int find(int x, vector<int> &parent) {
        return (parent[x] == x) ? x : find(parent[x], parent);
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int>parent;
        int c = connections.size();
        if (n-1 > c) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0], parent);
            int y = find(connections[i][1], parent);
            if (x != y)
                parent[y] = x;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
    }
};