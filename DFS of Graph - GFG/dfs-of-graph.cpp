// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    //   Iterative DFS
    //   vector<int> dfsOfGraph(int V, vector<int> adj[])
    //   {
    //       vector<int>res;
    //       vector<bool>visited(V, false);
    //       stack<int> st;
    //       st.push(0);
           
    //       while(!st.empty())
    //       {
    //           int curr= st.top();
    //           st.pop();
               
    //           if(visited[curr])
    //           continue;
    //           res.push_back(curr);
    //           visited[curr]=true;
               
    //           for(int i=adj[curr].size()-1; i>=0; i--)
    //           {
    //               st.push(adj[curr][i]);
    //           }
    //       }
    //       return res;
    //   }
    
    
    
    //RECURSIVE DFS
    void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &res){
        
        res.push_back(node);
        vis[node]=true;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj, res);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        
        vector<bool> vis(V, false);
        vector<int> res;
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, res);
            }
        }
        return res;
    }
       
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends