class Solution {
public:
    
//      void palindromic(string s, int left, int right, int& c) 
//      { 
//         while(left >=0 && right < s.size() && s[left] == s[right]) 
//         {
//             c++;
//             left--;
//             right++;
//         }
//     }
    
//     int countSubstrings(string s) {
        
//         int n= s.length();
//         int c=0;
        
//         for(int i=0; i<n; i++)
//         {
//             palindromic(s,i,i,c);//for odd string length
//             palindromic(s,i,i+1,c);//for odd string length
//         }
//         return c;
//     }
    
    
    //bottom-up approach
      int countSubstrings(string s) {
        int n = s.length(),total = 0;;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j<n;++j)
            {
                if(i==j)
                    dp[i][j] = 1; // Ex: a,b
                
                if(i+1 < n && s[i] == s[i+1])
                    dp[i][i+1] = 1; // Ex : aa,bb
                
                if(i>0 && j<n-1 && s[i-1] == s[j+1] && dp[i][j] == 1)
                    dp[i-1][j+1] = 1; // Ex : xax,xabax
                
                total += dp[i][j];
            }
        }
        return total;
    }
};