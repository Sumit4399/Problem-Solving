class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int row= accounts.size();
        int col=row>0 ? accounts[0].size():0;
        int res=INT_MIN;
        int sum=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {  
                sum+=accounts[i][j];
            }
            res=max(sum,res);
            sum=0;
        }
        return res;
    }
};