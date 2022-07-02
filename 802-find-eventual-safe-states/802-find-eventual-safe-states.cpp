class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node){
        
        color[node] = 1;
        
        for(auto curr : graph[node])
        {
            if((color[curr]==0 && dfs(graph, color, curr)) || color[curr]==1)
                return true;
        }
        
        color[node] = 2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n= graph.size();
        vector<int> color(n), res;
        
        for(int i=0; i<n; i++)
        {
            if(color[i]==2 || !dfs(graph, color, i))
                res.push_back(i);
        }
        return res;
    }
};