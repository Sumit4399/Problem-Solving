class Solution {
public:
    
    int sum(int n)
    {
        int s=0;
       while(n>0)
       {
           int res=n%10;
           s+=res;
           n=n/10;
       }
        return s;  
    }
    
    int countEven(int num) {
        
        int count=0;
        for(int i=1; i<=num; i++)
        {
            if(sum(i)%2==0)
                count++;
        }
        return count;
    }
};