// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{

    public:
    
    long m= 1000000007;
    long sum= 0;
    
    long power(int N,int R)
    {
        if(N==0)
        {
          return 0;
        }
        if(R==1)
        {
          return N;
        }
       
      sum= power(N, R/2);
       
      if(R%2==0)
      {
          return sum%m * sum%m;
      }
       
      return N* sum%m * sum%m;
    }

    
//   long sum=0; 
//   long  m=1000000007;
//   long power(int N,int R) 
//   {
//       if(N==0)
//       {
//           return 0;
//       }
//       if(R==1)
//       {
//           return N;
//       }
      
//       sum=power(N,R/2);
       
//       if(R%2==0)
//       {
//           return sum%m*sum%m;
//       }
       
//       return N*sum%m*sum%m;
//     }
    
};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends