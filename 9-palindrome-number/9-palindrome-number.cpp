class Solution {
public:
    bool isPalindrome(int x) {
        
        // string s = to_string(x);
        // int i = 0, j = s.size()-1;
        // while (i <= j) 
        // {
        //     if (s[i++] != s[j--])
        //     return false;
        // }
        // return true;
        
        //without converting the integer to a string
        int temp=x;
        long int rev=0;
        long int rem;
        
        while(x>0)
        {
            rem= x%10;
            rev= (rev*10)+rem;
            x=x/10;
        }
        
        return (temp==rev)? true: false;
    }
};