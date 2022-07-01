// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long memo(int f , int n , int tar, vector<vector<long long>> &dp){
        
        if(n==0)
        {
            return tar==0? 1 : 0;
        }
        
        if(dp[n][tar] != -1)
        return dp[n][tar];
        
        long long count=0;
        for(int i=1; i<=f; i++)
        {
            if(tar>=i)
            {
                count+= memo(f, n-1, tar-i, dp);
            }
        }
        
        return dp[n][tar]= count;
    }
    
    long long noOfWays(int f , int n , int tar) {
        
        vector<vector<long long>> dp(n+1, vector<long long> (tar+1, -1));
        return memo(f, n, tar, dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends