class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res;
        int i= num1.length()-1;
        int j= num2.length()-1;
        int carry=0;
        
        while(i>=0 && j>=0)
        {
            carry += (num1[i--]-'0') + (num2[j--]-'0');
            res.push_back(char(carry%10 + '0'));
            carry= carry/10;
        }
        
        while(i>=0)
        {
            carry += (num1[i--]-'0');
            res.push_back(char(carry%10 + '0'));
            carry= carry/10;
        }
        
        while(j>=0)
        {
            carry += (num2[j--]-'0');
            res.push_back(char(carry%10 + '0'));
            carry= carry/10;
        }
        
       if(carry > 0)
            res.push_back(char(carry%10 + '0'));
        reverse(res.begin(), res.end());
        
        return res;
        
        
//         string res;
//         int sum = 0;
//         int i = num1.size() - 1;
//         int j = num2.size() - 1;
        
        
//         while(i >= 0 && j >= 0)
//         {
//             sum += (num1[i--] - '0') + (num2[j--] - '0');
//             res.push_back(char(sum%10 + '0'));
//             sum = sum/10;
//         }
        
//         while(i >= 0)
//         {
//             sum += (num1[i--] - '0');
//             res.push_back(char(sum%10 + '0'));
//             sum = sum/10;
//         }
        
//         while(j >= 0)
//         {
//             sum += (num2[j--] - '0');
//             res.push_back(char(sum%10 + '0'));
//             sum = sum/10;
//         }
        
//         if(sum > 0)
//             res.push_back(char(sum%10 + '0'));
//         reverse(res.begin(), res.end());
        
//         return res;
    }
};