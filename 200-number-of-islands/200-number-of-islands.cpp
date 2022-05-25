class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int r, int c, int i, int j){
        
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]!='1')
            return;
        
        grid[i][j]= '2'; //mark as visited
        
        //calling dfs for all the 4 directions
        dfs(grid, r, c, i+1, j);
        dfs(grid, r, c, i, j+1);
        dfs(grid, r, c, i-1, j);
        dfs(grid, r, c, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int r= grid.size();
        if(r==0) return 0;
        int c= grid[0].size();
        int cot=0;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]=='1')
                {
                    cot++;
                    dfs(grid, r,c,i, j);
                                    
                }
            }
        }
        return cot;
    }
};