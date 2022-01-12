// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        
        //method-1
        // if(n==1)
        // return k;
        
        // int mod= 1e9+7;
        // long long same=k;
        // long long diff=k*(k-1);
        // long long total= (diff+same)%mod;
        
        // for(int i=3; i<=n; i++)
        // {
        //     same=diff;
        //     diff= (total*(k-1))%mod;
        //     total= (same+diff)%mod;
        // }
        // return total%mod;
        
        //method-2
        long long t[n+1];
        int mod= 1e9+7;
        
        t[0]=0;
        t[1]=k;
        t[2]=k*(k-1) + k;
        
        for(long long i=3; i<=n; i++)
        {
            t[i]= ((k-1)*t[i-1] + (k-1)*t[i-2])%mod;
        }
        
        return t[n];
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends