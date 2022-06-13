class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& Prob, int start, int end) {
        
        vector<bool> vis(n, false);
        priority_queue<pair<double, int>> pq;
        pq.push({(double)1.0, start});
        
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            graph[edge[0]].push_back({edge[1], Prob[i]});
            graph[edge[1]].push_back({edge[0], Prob[i]});
        }
    
        while(!pq.empty())
        {
            auto[pb, pos]= pq.top();
            pq.pop();
            
            if(pos==end)
                return pb;
            
            if(vis[pos]==true)
                continue;
            vis[pos]=true;
            
            for(auto it : graph[pos])
            {
                //if(vis[it.first] != true)
                    pq.push({pb*it.second, it.first});
            }
        }
        return 0;
    }
};