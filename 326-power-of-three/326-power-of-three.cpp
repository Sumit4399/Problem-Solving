class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n==1)
            return true;
        if(n<3)
            return false;
        
        int div=-1;
        int rem=-1;
        
        while(n>1)
        {
            div= n/3;
            rem= n%3;
            if(rem!=0)
                return false;
            n=n/3;
        }
        return true;
    }
};