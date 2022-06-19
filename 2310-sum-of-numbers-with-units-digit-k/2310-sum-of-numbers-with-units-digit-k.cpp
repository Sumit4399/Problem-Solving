class Solution {
public:
    int minimumNumbers(int num, int k) {
        
//         if(num==0)
//             return 0;
//         if(num==k)
//             return 1;
//         if(num>0 && k==1 ) 
//             return num;
        
//         int c=0;
//         int t= 0;
//         int k1=k;
        
//         while(k1<=num)
//         {
//             t= num-k1;
//             if(t%10==k && t>k1)
//             {
//                 c++;
//             }
//             t=0;
//             k1= k1+10;
//         }
        
//         if(c==0)
//             return -1;
        
//         return c;
        
        
        if (num == 0) return 0;
        for (int i = 1; i <= 10; ++i)
            if ((i * k) % 10 == num % 10 && i * k <= num) return i;
        return -1;
    }
};