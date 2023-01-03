class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int del=0;
        int r = strs.size();
        int c = strs[0].size();
        
        for(int j=0; j<c; j++)
        {
            for(int i=0; i<r-1; i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};