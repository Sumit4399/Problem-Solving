class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int curr_room= q.front();
            vis[curr_room]=true;
            q.pop();
            
            for(auto it : rooms[curr_room])
            {
                if(vis[it]==false)
                    q.push(it);
            }
        }
        
        for(auto it: vis)
        {
            if(it==false)
                return false;
        }
        return true;
    }
};