// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    
    bool memo(string a, string b, string c, int l1, int l2, int l3, 
    vector<vector<int>> &dp){
        
        if(l1<0 && l2<0 && l3<0)
        return true;
        
        if(l1>=0 && l2>=0 && dp[l1][l2] != -1)
        return dp[l1][l2];
        
        //1st case- if curr char in a=b=c
        if(l1>=0 && a[l1] == c[l3] && l2>=0 && b[l2] == c[l3])
        return dp[l1][l2]= (memo(a,b,c, l1-1, l2, l3-1, dp) || memo(a,b,c, l1, l2-1, l3-1, dp));
        
        
        //2nd case- if curr char in a==c
        else if(l1>=0 && a[l1] == c[l3])
        return memo(a,b,c, l1-1, l2, l3-1, dp);
        
        
        //3nd case- if curr char in b==c
        else if(l2>=0 && b[l2] == c[l3])
        return memo(a,b,c, l1, l2-1, l3-1, dp);
    }
    
    bool isInterleave(string a, string b, string c) 
    {
        int l1= a.size();
        int l2= b.size();
        int l3= c.size();
        
        vector<vector<int>> dp(l1, vector<int> (l2, -1));
        
        return memo(a, b, c, l1-1, l2-1, l3-1, dp);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends