// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    
    int mod= 1000000007;
    int countFriendsPairings(int n) 
    { 
        int t[n+1];
        for(long long int i=0; i<=n; i++)
        {
            if(i<=2)
            t[i]=i;
            
            else
            t[i]= (t[i-1] + (i-1)*t[i-2])%mod;
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
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends