class Solution {
public:
    
//     void dfs(string s, string d, unordered_map<string, unordered_map<string, double>> mp, 
//              unordered_map<string, double> &vis, double &ans, double temp){
        
//         //base casas
//         if(vis.count(s))
//             return;
//         if(s==d)
//         {
//             ans=temp;
//         }
        
//         vis[s]=1;
//         for(auto it: mp[s])
//         {
//             dfs(it.first, d, mp, vis, ans, temp*it.second);
//         }
//     }
    
    
//     vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        
//         //forming the graph for bi-directional given pairs
//         unordered_map<string, unordered_map<string, double>> mp;
//         for(int i=0; i<eq.size(); i++)
//         {
//             mp[eq[i][0]].insert({eq[i][1], val[i]});
//             mp[eq[i][1]].insert({eq[i][0], 1.0/val[i]});
//         }
        
//         vector<double> res;
//         //solving each query pair
//         for(int i=0; i<que.size(); i++)
//         {
//             string source= que[i][0];
//             string dest= que[i][1];
            
//             unordered_map<string, int> vis;
//             double ans= -1.0;
//             double temp= 1;
            
//             //calling dfs traversal
//             dfs(source, dest, mp, vis, ans, temp);
//             res.push_back(ans);
//         } 
        
//         return res;
    
          
           double dfs(unordered_map<string, unordered_map<string , double>>&graph, string a , string& b , unordered_set<string>&visited){
        if(graph[a].find(b) != graph[a].end()) 
            return graph[a][b];
        
        for(auto v : graph[a]){
            if(visited.find(v.first) == visited.end()){
                visited.insert(v.first);
                double dist = dfs(graph,v.first,b,visited );
                    if(dist) {
                        graph[a][b] = v.second * dist;
                        return graph[a][b];
                    }
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result; 
        unordered_map<string, unordered_map<string , double>> graph; 
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]] = (values[i]); 
            graph[equations[i][1]][equations[i][0]] = (double) 1/(values[i]); 
        }
        for(int i=0;i<queries.size();i++){           
            unordered_set<string> visited;             
            double val = dfs(graph , queries[i][0] , queries[i][1] , visited );
            if(!val)
                result.push_back(double(-1.0));
            else 
                result.push_back(val);
        }
            
        return result;
    
    }
};