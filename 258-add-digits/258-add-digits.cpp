class Solution {
public:
    int addDigits(int num) {
        
        int sum=0;
        while(num>9){
            sum= num%10;
            num= num/10;
            num+=sum;
            // if(num==0 && sum>9)
            // {
            //     num=sum;
            //     sum=0;
            // }
        }
        
        return num;
    }
};