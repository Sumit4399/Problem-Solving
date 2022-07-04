// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long memo(int i, int j, int arr[], vector<vector<long long>> &dp){
        
        if(i>=j)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        //if we take first element
        long long first = arr[i] + min(memo(i+2, j, arr, dp), memo(i+1, j-1, arr, dp));
        
        //if we take last element
        long long last = arr[j] + min(memo(i+1, j-1, arr, dp), memo(i, j-2, arr, dp));
        
        return dp[i][j] = max(first, last);
    }
    
    long long maximumAmount(int arr[], int n){
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return memo(0, n-1, arr, dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends