class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        
//         vector<bool> ans(que.size(),false);
//         if(pre.size()==0)
//             return ans;
        
//         //creating adj list from given vector pair
//         vector<int> adj[num];
//         for(auto it : pre)
//         {
//             adj[it[0]].push_back(it[1]);
//         }
        
//         //find indegree of each node
//         queue<int>q;
//         vector<int> indegree(num,0);
//         for(int i=0; i<num; i++)
//         {
//             for(auto it : adj[i])
//             {
//                 indegree[it]++;
//             }
//         }
        
//         //push node to queue if it has 0 indegree
//         for(int i=0; i<num; i++)
//         {
//             if(indegree[i]==0)
//             {
//                 q.push(i);
//             }
//         }
        
//         vector<int> res;
//         while(!q.empty())
//         {
//             int node= q.front();
//             q.pop();
//             res.push_back(node);
            
//             //decrease indegree of curr node pushed into the queue
//             for(auto it : adj[node])
//             {
//                 indegree[it]--;
//                 //if found zero push it into queue
//                 if(indegree[it]==0)
//                 {
//                     q.push(it);
//                 }
//             }
//         }
        
        
//         for(int i=0; i<que.size(); i++)
//         {
//             for(int j=0; j<res.size(); j++)
//             {
//                 if(que[i][0]==res[j])
//                     ans[i]= false;
                
//                 if(que[i][1]==res[j])
//                     ans[i]= true;
//             }
//         }
        
//         return ans;
        
        int p = pre.size();
        int qe = que.size();
        vector<bool> result(qe,0);
        vector<vector<int>> adj(n);
        vector<vector<bool>> possible(n,vector<bool>(n,0));
        
        for(auto &p : pre) 
            adj[p[0]].push_back(p[1]);
       
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
            while(!q.empty()){
                int course = q.front();
                q.pop();
                for(int v : adj[course]) {
                    if(!possible[i][v]){
                        possible[i][v] = 1;
                        q.push(v);
                    }
                }                
            }
        }
        
        for(int i=0;i<qe;i++)
            result[i] = possible[que[i][0]][que[i][1]];
        
        return result;
    }
};