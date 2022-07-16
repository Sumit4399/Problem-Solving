class Solution {
public:
    
    void dfs(int i, int j, int r, int c, vector<vector<int>>& grid1,
            vector<vector<int>>& grid2){
        if(i<0 || j<0 || j>=c || i>=r || grid2[i][j]==0)
            return;
        
        grid2[i][j]=0;
        
        //calling dfs in all 4 directions
        dfs(i-1, j, r, c, grid1, grid2);
        dfs(i, j-1, r, c, grid1, grid2);
        dfs(i+1, j, r, c, grid1, grid2);
        dfs(i, j+1, r, c, grid1, grid2);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int res=0;
        int r= grid1.size();
        int c= grid2[0].size();
        
        //dfs for making grid2 zero if its not a sub-island
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid2[i][j]==1 && grid1[i][j]==0)
                {
                    dfs(i, j, r, c, grid1, grid2);
                }
            }
        }
        
        //dfs for counting sub-island
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid2[i][j]==1 && grid1[i][j]==1)
                {
                    res++;
                    dfs(i, j, r, c, grid1, grid2);
                }
            }
        }
        return res;
    }
};