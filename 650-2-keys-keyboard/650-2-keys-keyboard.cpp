class Solution {
public:
    int minSteps(int n) {
        
        int res=0;
        int temp=2;
        
        while(n!=1)
        {
            if(n%temp==0)
            {
                n=n/temp;
                res+=temp;
            }
            else
                temp++;
        }
        
        return res;
    }
};