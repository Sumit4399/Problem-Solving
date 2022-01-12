// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    
    //recursive approach
    // int t[10005];
    // int solve(int l, int x, int y, int z)
    // {
    //     if(l==0)
    //     return 0;
        
    //     if(t[l]!=-1)
    //     return t[l];
        
    //     int a= INT_MIN;
    //     int b= INT_MIN;
    //     int c= INT_MIN;
        
    //     if(x<=l)
    //     {
    //         a=solve(l-x,x,y,z);
    //     }
    //     if(y<=l)
    //     {
    //         b=solve(l-y,x,y,z);
    //     }
    //     if(y<=l)
    //     {
    //         b=solve(l-z,x,y,z);
    //     }
        
    //     return t[l]= 1+max({a,b,c});
    // }
    
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0]=0;
        
        for(int i=1; i<=n; i++)
        {
            int a= INT_MIN;
            int b= INT_MIN;
            int c= INT_MIN;
            
            if(i>=x)
            {
                a=1+dp[i-x];
            }
            if(i>=y)
            {
                b=1+dp[i-y];
            }
            if(i>=z)
            {
                c=1+dp[i-z];
            }
            
            dp[i]= max({a,b,c});
        }
        return (dp[n]<0)? 0:dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends