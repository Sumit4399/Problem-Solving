// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int memo(int i, int j, int arr[], vector<vector<int>> &dp){
        
        if(i>j)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int first= arr[i] + min(memo(i+1, j-1, arr, dp), memo(i+2, j, arr, dp));
        
        int last = arr[j] + min(memo(i+1, j-1, arr, dp), memo(i, j-2, arr, dp));
        
        return dp[i][j]= max(first, last);
    }
    
    bool is1winner(int n,int arr[]) {
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int ans= memo(0, n-1, arr, dp);
        int tot=0;
        for(int i=0; i<n; i++)
        {
            tot+= arr[i];
        }
        
        if((tot-ans) <= ans)
        return true;
        
        else
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends