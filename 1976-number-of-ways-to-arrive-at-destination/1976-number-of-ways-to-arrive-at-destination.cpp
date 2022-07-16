
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        long long mod= (long long) (1e9+7);
        
        //create the graph
        vector<pair<long long, long long>> adj[n];
        for(auto it: roads)
        {
            long long u= it[0];
            long long v= it[1];
            long long wt= it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        //now use dijstra to find the shortest-path and dp to calculate the no. of ways
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,           greater<pair<long long, long long>>> pq;
        
        vector<long long> dis(n+1, 1e18); //store shortest distance
        // for(int i=0; i<n; i++)
        // {
        //     dis[i]= 1e18;
        // }
        vector<long long> ways(n+1, 0); //to store ways
        ways[0]=1;
        pq.push({0, 0});
        dis[0] = 0;
        
        while(!pq.empty())
        {
            auto[d, node]= pq.top();
            pq.pop();
            
            if (d > dis[node]) continue; 
            
            for(auto it : adj[node])
            {
                long long adj_node= it.first;
                long long adj_node_dis= it.second;
                
                if(dis[adj_node] > dis[node] + adj_node_dis)
                {
                    dis[adj_node] = dis[node] + adj_node_dis;
                    ways[adj_node] = ways[node];
                    pq.push({dis[adj_node], adj_node});
                }
                
                else if(dis[adj_node] == dis[node] + adj_node_dis)
                {
                    ways[adj_node] = (ways[adj_node] + ways[node])%mod;
                }
            }
            
        }
        return ways[n-1];
    }
};