// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
   public: 
        int memo(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!= -1)
            return dp[i][j];
        
        int up= memo(i-1, j, dp);
        int left = memo(i, j-1, dp);
        
        return dp[i][j]= up + left;
    }
    
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memo(m-1, n-1, dp);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends