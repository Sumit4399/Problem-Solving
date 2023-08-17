class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n= mat.size();
        int m= mat[0].size();
        queue<pair<int, int>> q;
        
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty())
        {
            int i= q.front().first;
            int j= q.front().second;
            
            if(i-1>=0 && ans[i][j] +1 < ans[i-1][j])
            {
                ans[i-1][j]= ans[i][j] +1;
                q.push({i-1, j});
            }
            
            if(i+1<n && ans[i][j] +1 < ans[i+1][j])
            {
                ans[i+1][j]= ans[i][j] +1;
                q.push({i+1, j});
            }
            
            if(j-1>=0 && ans[i][j] +1 < ans[i][j-1])
            {
                ans[i][j-1]= ans[i][j] +1;
                q.push({i, j-1});
            }
            
            if(j+1<m && ans[i][j] +1 < ans[i][j+1])
            {
                ans[i][j+1]= ans[i][j] +1;
                q.push({i, j+1});
            }
            
            q.pop();
        }
        
        return ans;
    }
};