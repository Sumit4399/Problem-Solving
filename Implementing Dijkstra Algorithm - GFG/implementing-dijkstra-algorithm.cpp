// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //vector<int> res;
        
        //min-heap for storing pair(dist, node) from the given source
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        //vector array for calculating shortest distance
        vector<int> dist(V, INT_MAX);
        
        dist[S]=0; //from source-to-source dis is always 0
        pq.push({0, S});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;  //dist
            int prev = pq.top().second; //node
            pq.pop();
            
            for(auto it : adj[prev])
            {
                //traversing the neighbours nodes
                int next = it[0];
                int next_dist= it[1];
                
                if(dist[next] > dist[prev] + next_dist)
                {
                    dist[next]= dist[prev] + next_dist; //update the shorter dist
                    pq.push({dist[next], next});
                }
            }
        }
        
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends