// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // unordered_map<string, int> mp;
    // int solve(string s, int i, int j, bool istrue)
    // {
    //     if(i>j)
    //     return 0;
    //     if(i==j)
    //     {
    //         if(istrue == true)
    //         return s[i]= 'T';
            
    //         else
    //         return s[i]='F';
    //     }
        
    //     string temp="";
    //     temp.push_back(s[i]);
    //     temp.push_back(s[j]);
        
    //     if(istrue)
    //     temp.push_back('1');
        
    //     else
    //     temp.push_back('0');
        
    //     if(mp.find(temp)!=mp.end())
    //     return mp[temp];
        
    //     int ans=0;
    //     for(int k=i+1; k<=j-1; k=k+2)
    //     {
    //         int lt= solve(s,i, k-1, true);
    //         int lf= solve(s,i, k-1, false);
    //         int rt= solve(s,k+1, j, true);
    //         int rf= solve(s,k+1, j, false);
            
    //         //evaluation of characters
    //         if(s[k]== '&')
    //         {
    //             if(istrue= true)
    //             ans = ans +  lt*rt;
                
    //             else
    //             ans= ans + (lt*rf) + (lf*rt) + (lf*rf); 
    //         }
            
    //         if(s[k]== '|')
    //         {
    //             if(istrue= true)
    //             ans = ans + (lt*lf) + (lt*rt) + (lf*rt);
                
    //             else
    //             ans = ans + (lf*rf); 
    //         }
            
    //         if(s[k]== '^')
    //         {
    //             if(istrue= true)
    //             ans = ans+ (lt*rf) + (lf*rt);
                
    //             else
    //             ans= ans +(lt*rt) + (lf*rf); 
    //         }
    //     }
    //     return mp[temp]= ans;
    // }
    
    // int countWays(int N, string S){
        
    //     mp.clear();
    //     bool istrue= true;
    //     return solve(S,0, N-1, istrue);
    // }
    
    
            int t[201][201][2];
int solve(string& S, int i, int j, bool isTrue){
if(i>j){
t[i][j][isTrue]=false;
}
if(i==j){
if(isTrue)
t[i][j][1]=S[i]=='T';
else
t[i][j][0]=S[i]=='F';

return t[i][j][isTrue];
}
if(t[i][j][isTrue] != -1){
return t[i][j][isTrue];
}
int ans=0;
for(int k=i+1; k<=j-1;k+=2){
int LT=solve(S, i, k-1, true);
int LF=solve(S, i, k-1, false);
int RT=solve(S, k+1, j, true);
int RF=solve(S, k+1, j, false);

if (S[k] == '|')
{
if (isTrue == true)
ans += (LT * RF) + (LF * RT) + (LT * RT);
else
ans += (LF * RF);
}

else if (S[k] == '&')
{
if (isTrue == true)
ans += (LT *RT);
else
ans += (LF * RT) + (LT * RF) + (LF * RF);
}

else if (S[k] == '^')
{
if (isTrue == true)
ans += (LT * RF) + (LF * RT);
else
ans += (LT * RT) + (LF * RF);
}
}
return t[i][j][isTrue]=ans%1003;
}
int countWays(int N, string S){
t[N][N][2];
memset(t, -1, sizeof(t));
return solve(S, 0, N-1, true);
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends