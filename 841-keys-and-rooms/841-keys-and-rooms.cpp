class Solution {
public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
//         int n=rooms.size();
//         vector<bool> vis(n, false);
//         queue<int> q;
//         q.push(0);
        
//         while(!q.empty())
//         {
//             int curr_room= q.front();
//             vis[curr_room]=true;
//             q.pop();
            
//             for(auto it : rooms[curr_room])
//             {
//                 if(vis[it]==false)
//                     q.push(it);
//             }
//         }
        
//         for(auto it: vis)
//         {
//             if(it==false)
//                 return false;
//         }
//         return true;
//     }
    
    
    //dfs approach
    void dfs(vector<vector<int>>& rooms, vector<bool> &vis, int i){
        
        vis[i]=true;
        for(auto it : rooms[i])
        {
            if(!vis[it])
            dfs(rooms, vis, it);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<bool> vis(n, false);
        
        //calling the function
        dfs(rooms, vis, 0);
        
        for(auto it: vis)
        {
            if(it==false)
                return false;
        }
        return true;
    }
};