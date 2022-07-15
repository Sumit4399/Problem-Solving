class Solution {
public:
    bool judgeSquareSum(int c) {
        
        if(c<3)
            return true;
        
        long long int l= 0; 
        long long int h= sqrt(c);
        
        while(l<=h)
        {
            long long int mid= l*l + h*h;
            
            if(mid==c)
                return true;
            
            else if(mid>c)
                h--;
            
            else
                l++;
        }
        
        return false;
    }
};