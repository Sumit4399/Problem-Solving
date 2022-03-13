class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        
        int res=0, temp=0;
        
        //terminating condition
        if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        
        temp= grid[i][j];
        grid[i][j]=0; //making the path visited
        
        //checking all the 4 possible max path
        res= max(res, dfs(grid, i-1, j));
        res= max(res, dfs(grid, i+1, j));
        res= max(res, dfs(grid, i, j-1));
        res= max(res, dfs(grid, i, j+1));
        
        grid[i][j]= temp;  //backtracking step
        
        return res+temp;
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
      int res=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]>0)
                {
                    res= max(res, dfs(grid, i, j));
                }
            }
        }
        
        return res;
    }
};