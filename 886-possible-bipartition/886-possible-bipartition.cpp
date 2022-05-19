class Solution {
public:
    
    bool bipartite_bfs(int src, vector<vector<int>> &adj, vector<int> &color){
        
        queue<int> q;
        q.push(src);
        color[src]=1;
        
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(color[it]==-1) //number not visited
                {
                    color[it]= 1- color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        //bipartition graph using bfs(graph coloring)
        //Constructing graph using Adjacency list
        vector<vector<int>> adj(n+1);
        for (auto x: dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> color(n+1,-1);
        for(int i=1; i<=n; i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite_bfs(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};