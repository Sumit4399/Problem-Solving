class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int c=0;
        int row=matrix.size();
        int col=row>0 ? matrix[0].size():0;
        //int dp[row][col];
        
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(i>0 && j>0 && matrix[i][j]>0)
                {
                    matrix[i][j]= min({matrix[i-1][j-1], matrix[i-1][j],
                                   matrix[i][j-1]})+1;
                }
                c+= matrix[i][j];
            }
        }
        return c;
    }
};




// int rows = matrix.size();
//         int cols = rows>0 ? matrix[0].size() :0;
//         int dp[rows+1][cols+1];
//         memset(dp,0,sizeof(dp));
//         //vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
//         int maxlen=0;
//         for (int i = 1; i <= rows; i++)
//         {
//              for (int j = 1; j <= cols; j++)
//              {
//                  if(matrix[i-1][j-1]=='1')
//                  {
//                      dp[i][j]= min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;
//                      maxlen= max(maxlen, dp[i][j]);
//                  }
//              }
//         }
//         return maxlen*maxlen;