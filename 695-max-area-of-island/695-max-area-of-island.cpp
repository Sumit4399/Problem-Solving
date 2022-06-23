class Solution {
public:
    
    void dfs(int i, int j, int r, int c, vector<vector<int>>& grid, int &temp){
        if(i<0 || j<0 || j>=c || i>=r || grid[i][j]==0)
            return;
        
        temp++;
        grid[i][j]=0;
        
        //calling dfs in all 4 directions
        dfs(i-1, j, r, c, grid, temp);
        dfs(i, j-1, r, c, grid, temp);
        dfs(i+1, j, r, c, grid, temp);
        dfs(i, j+1, r, c, grid, temp);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int res=0;
        int r= grid.size();
        int c= grid[0].size();
        int temp=0;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                    temp=0;
                    dfs(i, j, r, c, grid, temp);
                    res= max(res, temp);
                }
            }
        }
        return res;
    }
};