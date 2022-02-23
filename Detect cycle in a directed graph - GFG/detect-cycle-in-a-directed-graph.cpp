// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recstack, int i){
        visited[i] = true;
        recstack[i] = true;
        for(auto &e : adj[i]){
            if(visited[e] == false && dfs(V, adj, visited, recstack, e)){
                return true;
            }
            else if(recstack[e] == true){
                return true;
            }
        }
        recstack[i] = false;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recstack(V, false);
        bool isCyclic = false;
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                isCyclic = dfs(V, adj, visited, recstack, i);
            }
            if(isCyclic){
                return true;
            }
        }
        return false;
    }
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