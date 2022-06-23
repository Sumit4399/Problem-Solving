class Solution {
public:
    
    int countServers(vector<vector<int>>& grid) {
        
        //brute force (O(N*N*N))
//         int res=0;
//         int r= grid.size();
//         int c= grid[0].size();
//         bool temp= false;
        
//         for(int i=0; i<r; i++)
//         {
//             for(int j=0; j<c; j++)
//             {
//                 temp=false;
//                 if(grid[i][j]==1)
//                 {
//                     for(int k=0; k<c; k++)
//                     {
//                         if(grid[i][k] == 1 && k!=j)
//                         {
//                             temp= true;
//                             continue;
//                             //break;
//                         }
//                     }
//                     for(int k=0; k<r; k++)
//                     {
//                         if(grid[k][j] == 1 && k!=i)
//                         {
//                             temp= true;
//                         }
//                     }
//                     if(temp==true)
//                     {
//                         res++;
//                     }
//                 }
//             }
//         }
//         return res;
        
        
        
    //OPTIMSED (O(N*N))
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<int> row_count(n, 0);
        vector<int> col_count(m, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] && (row_count[i] >= 2 || col_count[j] >= 2 ))
                {
                    count++;
                }
            }
        }
        
        return count;

    }
};