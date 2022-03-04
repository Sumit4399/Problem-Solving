// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//DFS approach
// 	void topo(int node, vector<bool>& vis, stack<int>&st, vector<int> adj[]){
	    
// 	    vis[node]= true;
// 	    for(auto it : adj[node])
// 	    {
// 	        if(!vis[it])
// 	        {
// 	            topo(it, vis, st, adj);
// 	        }
// 	    }
// 	    st.push(node);
// 	}
	
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int> st;
// 	    vector<bool> vis(V,false);
	    
// 	    for(int i=0; i<V; i++)
// 	    {
// 	        if(vis[i]==false)
// 	        {
// 	            topo(i, vis, st, adj);
// 	        }
// 	    }
	    
// 	    vector<int> res;
// 	    while(!st.empty())
// 	    {
// 	        res.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return res;
// 	}



//Function to return list containing vertices in Topological order. 
//BFS APPROACH (KAHN'S ALGO)
 	vector<int> topoSort(int V, vector<int> adj[]) {
 	    
 	    queue<int> q;
 	    //find indegree of each node
 	    vector<int> indegree(V,0);
 	    for(int i=0; i<V; i++)
 	    {
 	        for(auto it : adj[i])
 	        {
 	            indegree[it]++;
 	        }
 	    }
 	    
 	    //push the node to queue if any node has 0 indegree
 	    for(int i=0; i<V; i++)
 	    {
 	        if(indegree[i]==0)
 	        {
 	            q.push(i);
 	        }
 	    }
 	    
 	    vector<int> res;
 	    while(!q.empty())
 	    {
 	        int node=q.front();
 	        q.pop();
 	        res.push_back(node);
 	        //find indegree of curr node pushed into the queue
 	        for(auto it : adj[node])
 	        {
 	            indegree[it]--;
 	            //if found zero push it into queue
 	            if(indegree[it]==0)
 	            {
 	                q.push(it);
 	            }
 	        }
 	    }
 	    return res;
 	}

};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends