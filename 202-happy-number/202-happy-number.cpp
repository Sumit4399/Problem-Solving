class Solution {
public:
    
    int next(int n)
    {
        int sum=0;
        while(n>0){
            int d= n%10;
            n= n/10;
            sum +=d*d;
            
        }
        return sum;
    }
    bool isHappy(int n) {
        
        int slow=n;
        int fast=next(n);
        
        while(fast!=1 && slow!=fast)
        {
            slow= next(slow);
            fast= next(next(fast));
        }
        
        if(fast==1)
            return true;
        else 
            return false;
        
    }
};