class Solution {
public:
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j){
        int r= h.size();
        int c= h[0].size();
        
        vis[i][j]= true;
    
        //up
        if(i-1>=0 && vis[i-1][j]!=true && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
        
        //down
        if(i+1<r && vis[i+1][j]!=true && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
        
        //left
        if(j-1>=0 && vis[i][j-1]!=true && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
        
        //right
        if(j+1<c && vis[i][j+1]!=true && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        vector<vector<int>> ans;
        int r= h.size();
        int c= h[0].size();
        
        vector<vector<bool>> pac(r, vector<bool> (c));
        vector<vector<bool>> atl(r, vector<bool> (c));
        
        for(int i=0; i<r; i++)
        {
            dfs(h, pac, i, 0);
            dfs(h, atl, i, c-1);
        }
        
        for(int j=0; j<c; j++)
        {
            dfs(h, pac, 0, j);
            dfs(h, atl, r-1, j);
        }
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};