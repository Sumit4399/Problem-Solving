class Solution {
public:
    string removeDigit(string number, char digit) {
        
//         string res;
//         bool flag= false;
        
//         for(char c : number)
//         {
//             if(c==digit && flag== false)
//                 flag==true;
            
//             else if(c== digit && flag==true)
//                 res+= c;
            
//             else if(c!=digit)
//                 res+=c;
//         }
//         return res;
        
        int pos = -1, n = number.size();
        for(int i = n-1; i>=0;i--) 
        {
            if((number[i] == digit) && (pos == -1 || number[i+1]>number[i])) 
            {
                pos = i;
            }
        }
        return number.erase(pos,1);
    }
};