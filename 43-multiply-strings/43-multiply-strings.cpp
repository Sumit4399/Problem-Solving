#define ll unsigned long long int

class Solution {
public:
//     string multiply(string num1, string num2) {
        
//         ll sum=0, ans=0;
//         reverse(num2.begin(), num2.end());
//         reverse(num1.begin(), num1.end());
        
//         for(int i=0; i<num2.size(); i++)
//         {
//             int x=num2[i]-'0';
            
//             for(int j=0; j<num1.size(); j++)
//             {
//                 sum+=x*(num1[j]-'0')*pow(10, j);
//             }
            
//             ans+=sum*pow(10, i);
//             sum=0;
//         }
//         return to_string(ans);
//     }
    
    
    string multiply(string& A, string& B) {
        
        if(A == "0" || B == "0") return "0";
        string ans(size(A)+size(B), '0');
        
        for(int i = size(A)-1; i >= 0; i--) 
        {
            for(int j = size(B)-1; j >= 0; j--)
            {
                int res = (ans[i+j+1]-'0') + (A[i]-'0') * (B[j]-'0');
                ans[i+j+1] = res%10 + '0';  // ones place of multiplication result
                ans[i+j] += res/10;         // carry over to previous index if result >= 10
            }
        }
        
        if(ans[0] == '0') return ans.substr(1);
        return ans;
    }
};