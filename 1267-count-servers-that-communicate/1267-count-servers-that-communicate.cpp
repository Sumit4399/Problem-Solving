class Solution {
public:
    
//     void dfs(int i, int j, int r, int c, vector<vector<int>>& grid, int &temp){
//         if(i<0 || j<0 || j>=c || i>=r || grid[i][j]==0)
//             return;
        
//         temp++;
//         grid[i][j]=0;
        
//         //calling dfs in all 4 directions
//         dfs(i-1, j, r, c, grid, temp);
//         dfs(i, j-1, r, c, grid, temp);
//         dfs(i+1, j, r, c, grid, temp);
//         dfs(i, j+1, r, c, grid, temp);
        
//     }
    
    int countServers(vector<vector<int>>& grid) {
        int res=0;
        int r= grid.size();
        int c= grid[0].size();
        bool temp= false;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                temp=false;
                if(grid[i][j]==1)
                {
                    for(int k=0; k<c; k++)
                    {
                        if(grid[i][k] == 1 && k!=j)
                        {
                            temp= true;
                            continue;
                            //break;
                        }
                    }
                    
                    for(int k=0; k<r; k++)
                    {
                        if(grid[k][j] == 1 && k!=i)
                        {
                            temp= true;
                        }
                    }
                    
                    if(temp==true)
                    {
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
};