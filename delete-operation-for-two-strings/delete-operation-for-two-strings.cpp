class Solution {
public:
    
    //function to print LCS between two string
    int lcs(int x, int y, string s1, string s2)
    {
        //initialise
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
                    if(s1[i-1]==s2[j-1])
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
    
    
    int minDistance(string word1, string word2) {
        
        int a= word1.length();
	    int b= word2.length();
	    
	    int res= lcs(a,b,word1,word2);
	    
	    return a+b-2*res;
    }
};