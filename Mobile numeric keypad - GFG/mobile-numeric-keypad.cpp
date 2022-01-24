// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int n)
	{
		// Your code goes here
		     if (n == 1) return 10;
if (n == 2) return 36;
long long DP[10][n+1];
for (int i = 0; i <= 9; i++)
 DP[i][1] = 1;
for (int i = 2; i <= n; i++)
{
 long long a[10];
 a[0] = DP[0][i - 1] + DP[8][i - 1];
 a[1] = DP[1][i - 1] + DP[2][i - 1] + DP[4][i - 1];
 a[2]= DP[2][i - 1] + DP[1][i - 1] + DP[3][i - 1]+DP[5][i-1];
 a[3]= DP[3][i - 1] + DP[2][i - 1] + DP[6][i - 1];
 a[4]= DP[4][i - 1] + DP[1][i - 1] + DP[5][i - 1]+DP[7][i-1];
 a[5]= DP[5][i - 1] + DP[2][i - 1] + DP[4][i - 1] + DP[8][i - 1]+DP[6][i-1];
 a[6]= DP[6][i - 1] + DP[3][i - 1] + DP[5][i - 1] + DP[9][i - 1];
 a[7] = DP[7][i - 1] + DP[4][i - 1] + DP[8][i - 1];
 a[8]= DP[8][i - 1] + DP[0][i - 1] + DP[5][i - 1] + DP[7][i - 1] + DP[9][i - 1];
 a[9]= DP[9][i - 1] + DP[6][i - 1] + DP[8][i - 1];
 for (int j = 0; j <= 9; j++)
  DP[j][i] = a[j];
}
long long sum = 0;
for (int i = 0; i <= 9; i++)
 sum += DP[i][n];
return sum;
}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends