class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
            return false;
        if(n==1)
            return true;
        
        int div=-1;
        int rem=-1;
        
        while(n>1)
        {
            div= n/4;
            rem= n%4;
            if(rem!=0)
                return false;
            n=n/4;
        }
        return true;
    }
};