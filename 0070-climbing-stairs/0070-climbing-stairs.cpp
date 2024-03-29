class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=1)
        {
            return 1;
        }
        
        int t[n+1];
        t[1]=1;
        t[2]=2;
        
        for(int i=3; i<=n; i++)
        {
            t[i]= t[i-1] + t[i-2];
        }
        return t[n];
    }
    
 // space optimised code
    
//     public int climbStairs(int n) {
//         if (n <= 1) {
//             return 1;
//         }

//         int prev1 = 1;
//         int prev2 = 2;

//         for (int i = 3; i <= n; i++) {
//             int newValue = prev1 + prev2;
//             prev1 = prev2;
//             prev2 = newValue;
//         }

//         return prev2;
//     }

};