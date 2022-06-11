class Solution {
public:
    
//     int valid(int i, int j , vector<vector<int>>& grid){
        
//         if(i<0 || i>grid.size() || j<0 || j>grid[0].size() || grid[i][j]==0)
//             return 0;
//         else
//             return 1;
//     }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int r= grid.size();
        int c= grid[0].size();
        int res=0;
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                    res += (i == 0 || grid[i-1][j] == 0 ? 1 : 0);
                    res += (i == r-1 || grid[i+1][j] == 0 ? 1 : 0);
                    res += (j == 0 || grid[i][j-1] == 0 ? 1 : 0);
                    res += (j == c-1 || grid[i][j+1] == 0 ? 1 : 0);
                }
                
            }
        }
        return res;
    }
};