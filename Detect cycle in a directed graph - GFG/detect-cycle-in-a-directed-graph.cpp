// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    // bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recstack, int i){
    //     visited[i] = true;
    //     recstack[i] = true;
    //     for(auto &e : adj[i]){
    //         if(visited[e] == false && dfs(V, adj, visited, recstack, e)){
    //             return true;
    //         }
    //         else if(recstack[e] == true){
    //             return true;
    //         }
    //     }
    //     recstack[i] = false;
    //     return false;
    // }
    
    
    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<bool> visited(V, false);
    //     vector<bool> recstack(V, false);
    //     bool isCyclic = false;
    //     for(int i = 0; i < V; i++){
    //         if(visited[i] == false){
    //             isCyclic = dfs(V, adj, visited, recstack, i);
    //         }
    //         if(isCyclic){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    
   //Cycle Detection in Directed Graph using BFS(Kahn's Algorithm)
   bool isCyclic(int V, vector<int> adj[]){
       
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
 	    
 	    int res=0;
 	    while(!q.empty())
 	    {
 	        int node=q.front();
 	        q.pop();
 	        res++;
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
 	    
        return (res==V? false : true);
   }
// }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends