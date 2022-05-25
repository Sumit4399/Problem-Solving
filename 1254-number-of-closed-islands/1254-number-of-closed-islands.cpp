class Solution {
public:
    
     void dfs(vector<vector<int>>& grid, int r, int c, int i, int j){
        
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==1)
            return;
        
        grid[i][j] = 1; //mark as water
        
        //calling dfs for all the 4 directions
        dfs(grid, r, c, i+1, j);
        dfs(grid, r, c, i, j+1);
        dfs(grid, r, c, i-1, j);
        dfs(grid, r, c, i, j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
    
        int r= grid.size();
        if(r==0) return 0;
        int c= grid[0].size();
        int cot=0;
        
        //calling dfs only for boundary elements
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(i*j==0 || i==r-1|| j==c-1)
                {
                     if(grid[i][j]==0)
                    {
                        dfs(grid, r,c,i, j);
                    }
                }
            }
        }
        
        //calling dfs for land surrounded with water
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid, r,c,i, j);
                    cot++;
                }
            }
        }
        return cot;
    }
};