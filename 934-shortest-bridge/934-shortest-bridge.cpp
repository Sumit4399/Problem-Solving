class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || 
           vis[i][j]==true || grid[i][j]==0)
            return;
        
        vis[i][j]= true;
        grid[i][j]= 2;
        
        dfs(i-1, j, grid, vis);
        dfs(i, j-1, grid, vis);
        dfs(i+1, j, grid,vis);
        dfs(i, j+1, grid, vis);
   }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int x, y;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    x=i, y=j;
                    break;
                }
            }
        }
        
        dfs(x, y, grid, vis);
        
        vector<pair<int, int>> v1, v2;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               if(grid[i][j] ==1)
                   v1.push_back({i, j});
                
                else if(grid[i][j] == 2)
                    v2.push_back({i, j});
            }
        }
        
        int flip= INT_MAX;
        
        for(int i=0; i<v1.size(); i++)
        {
            for(int j=0; j<v2.size(); j++)
            {
                // int x1= v1[i].first;
                // int x2= v2[j].first;
                // int y1= v1[i].second;
                // int y2= v2[j].second;
                
                flip= min(flip, abs(v1[i].first-v2[j].first) + abs(v1[i].second-v2[j].second) -1);
            }
        }
        return flip;
    }
};