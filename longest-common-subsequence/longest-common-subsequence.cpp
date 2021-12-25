class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int x= text1.length();
        int y= text2.length();
        
         int t[x+1][y+1];
        for(int i=0; i<x+1; i++)
        {
            for(int j=0; j<y+1; j++)
            {
                if(i==0 || j==0)
                {
                    t[i][j]=0;
                }
                else
                {
                    if(text1[i-1] == text2[j-1])
                   {
                    t[i][j]= 1+ t[i-1][j-1];
                    }
                    else
                   {
                    t[i][j]= max(t[i-1][j], t[i][j-1]);
                   }
                }
            }
        }
         return t[x][y];
    }
};