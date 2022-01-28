class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        
        int m=a.size();
        int n=a[0].size();
        if(m==0||n==0) 
            return 0;
        //int dp[m][n];
        int res= INT_MAX;
        //memset(dp,INT_MAX,sizeof(dp));
        
        
        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0)//leftmost col
                {
                    a[i][j]+= min(a[i-1][j], a[i-1][j+1]);
                }
                else if(j==n-1)//rightmost col
                {
                    a[i][j]+= min(a[i-1][j], a[i-1][j-1]);
                }
                else
                {
                    a[i][j]+= min({a[i-1][j], a[i-1][j+1], 
                                  a[i-1][j-1]});
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            res= min(res, a[m-1][i]);
            
        }
        return res;
    }
};