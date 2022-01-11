// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int t[n+1][m+1];
        
        for(int j=m-1; j>=0; j--)
        {
            for(int i=0; i<n; i++)
            {
                int right= (j==m-1)? 0 : t[i][j+1];
                
                int right_up= (i==0 || j==m-1)? 0 : t[i-1][j+1];
                
                int right_down= (i==n-1 || j==m-1)? 0 : t[i+1][j+1];
                
                t[i][j]= M[i][j] + max(right, max(right_up, right_down));
            }
        }
        
        int res= t[0][0];
        for(int i=0; i<n; i++)
        {
            res= max(res,t[i][0]);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends