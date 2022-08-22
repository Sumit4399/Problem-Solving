class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<int> dir= {-1, 0, 1, 0, -1}; //storing all 4 direction
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int, int>> q;
        int fresh=0;
        int mnt=-1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    q.push({i, j});
            }
        }
        
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
                auto[fir, sec]= q.front();
                q.pop();
                
                for(int i=0; i<4; i++)
                {
                    int r= fir + dir[i];
                    int c= sec + dir[i+1];
                    
                    if(r>=0 && r<n && c>=0 && c<m &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                }
            }
            mnt++;
        }
        
        if(fresh>0)
            return -1;
        if(mnt==-1)
            return 0;
        return mnt;
    }
};