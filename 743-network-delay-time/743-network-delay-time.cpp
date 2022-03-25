class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
			vector<int>dist(N+1, INT_MAX);
			
			pq.push({0, K});
			dist[K] = 0;
			
			unordered_map<int, vector<pair<int, int>>>adj;
			for (auto i:times)
				adj[i[0]].push_back({i[1],i[2]});
			
			while (!pq.empty()) {
				auto p = pq.top();
				pq.pop();
				
				int u = p.second;
				for (auto i:adj[u]) {
					int v = i.first;
					int w = i.second;
					
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						pq.push({dist[v], v});
					}
				}
			}
			
			int res = 0;
			for (int i = 1; i <= N; i++)
				res = max(res, dist[i]);
			
			return res == INT_MAX ? -1 : res;
    }
};