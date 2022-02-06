// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // int mod= 1e9+7;
    // int nCr(int n, int r){
        
    //     int t[n+1][r+1];
    //     for(int i=0; i<n+1; i++)
    //     {
    //         for(int j=0; j<r+1; j++)
    //         {
    //             if(i==j || j==0)
    //             t[i][j]=1;
                
    //             else if(i<j)
    //             t[i][j]=0;
    //         }
    //     }
        
    //     //standard formula fpr binomial coefficient
    //     //C(n, k) = C(n-1, k-1) + C(n-1, k)
    //     //C(n, 0) = C(n, n) = 1
    //     for(int i=1; i<n+1; i++)
    //     {
    //         for(int j=1; j<r+1; j++)
    //         {
    //             t[i][j]= (t[i-1][j-1]%mod + t[i-1][j]%mod)%mod;
    //         }
    //     }
        
    //     return t[n][r]%mod;
    // }
    
    
    int m=1e9+7;
    int find(int n, int r, vector<vector<int>> &dp){
        
      if(n==r || r==0)
        return 1;
        
      if(n<r)
        return 0;
      
    //   if(r==1)
    //     return dp[n][r]=n;
      
      
        
      if(dp[n][r]!=-1)
        return dp[n][r]%m;    
    
      return dp[n][r]=(find(n-1, r, dp)%m+find(n-1, r-1, dp)%m)%m;
}
    int nCr(int n, int r){
        // code here
    //   int dp[1001][1001];
    vector<vector<int>> v(n+1,vector<int> (r+1,-1));
    //   memset(dp, -1, sizeof(dp));--
      
      return find(n, r, v);
      
     // return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends