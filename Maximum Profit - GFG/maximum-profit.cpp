// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        
        int dp[n+1][k+1][2];
        memset(dp,0,sizeof(dp));
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int>(2,0)));
        
        for(int i=n-1; i>=0; i--)
        {
            for(int rem=1; rem<=k; rem++)
            {
                for(int hold=0; hold<2; hold++)
                {
                    int no= dp[i+1][rem][hold];
                    int yes;
                    if(hold==1) //selling stock
                    {
                        yes= prices[i] + dp[i+1][rem-1][0];
                    }
                    else //(hold==0) buying stock
                    {
                        yes= -prices[i] + dp[i+1][rem][1];
                    }
                    //recurrence relation
                    dp[i][rem][hold]= max(no, yes);
                }
            }
        }
        
        return dp[0][k][0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends