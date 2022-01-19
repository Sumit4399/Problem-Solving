class Solution {
public:
   // int numDecodings(string s) {
        
//         int n= s.length();
//          if(n==1){
//             if(s[0]=='0')
//                 return 0;
//         }
        
//         vector<int> dp(n,0);
//         dp[0]=1;
        
//         if(n>=2){
//             if(s[0]=='0')
//                 return 0;
//         }
        
//         for(int i=1; i<n; i++)
//         {
//             if(s[i-1]=='0' && s[i]=='0')
//                 dp[i]=0;
            
//             else if(s[i-1]=='0' && s[i]!=0)
//                 dp[i]=dp[i-1];
            
//             else if(s[i-1]!='0' && s[i]=='0')
//             {
//                 if(s[i-1]=='1' || s[i-1]=='2')
//                     dp[i]= (i>=2 ? dp[i-2] : 1);
//                 else
//                     dp[i]=0;
//             }
            
//             else
//             {
//                 if(stoi(s.substr(i-1, i+1)) <=26)
//                     dp[i]= dp[i-1] + (i>=2 ? dp[i-2] : 1);
//                 else
//                     dp[i]= dp[i-1];
//             }  
//         }
        
//         return dp[n-1];
        
        
         int numDecodings(string s) {
        if(s.length()==1){
            if(s[0]=='0')
                return 0;
        }
        
        vector<int> dp(s.size(),0);
        dp[0]=1;
        
        if(s.length()>=2){
            if(s[0]=='0')
                return 0;
        }
        
        
          for(int i=1;i<s.size();i++){
        if(s[i-1]=='0' && s[i]=='0')//case 1
        {
            dp[i]=0;
        }
        else if(s[i-1]=='0' && s[i]!='0')//case 2
        {
            dp[i]=dp[i-1];
        }
        else if(s[i-1]!='0' &&s[i]=='0')//case 3
        {
            if(s[i-1]=='1' || s[i-1]=='2')
            dp[i]=(i>=2?dp[i-2]:1);
            else
            dp[i]=0;
        }
        else if(s[i-1]!='0' && s[i]!='0'){
            if(stoi(s.substr(i-1,2))<=26)
            dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
            else
            dp[i]=dp[i-1];
        }
    }
        return dp[s.length()-1];

    }
};