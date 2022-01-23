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

