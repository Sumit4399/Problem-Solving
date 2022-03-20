class Solution {
public:
    
 //   vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
//         vector<int> res;
//         unordered_set<int> set;
//         for(int i=0; i<graph.size(); i++)
//         {
//             if(graph[i].size()==0)
//                 set.insert(i);
//         }
        
//         for(int i=0; i<graph.size(); i++)
//         {
//             bool isRes = true;
//             for(int j=0;j<graph[i].size();j++) {
//                 if(set.count(graph[i][j])) {
//                     continue;
//                 }
//                 else {
//                     isRes = false;
//                     break;
//                 }
//             }
//             if(isRes) {
//                 res.push_back(i);
//             }
//         }
//         return res;
        
        
        
         bool DFSRec(int s, vector<bool>&visited, vector<bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[s] = true;
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[s] = true;
            }
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        vector<bool>visited(n, false), dfsVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
};