class Solution {
public:
    
    int titleToNumber(string columnTitle) {
        
        int n= columnTitle.length();
        int res=0;
         
        for(int i=0; i<n; i++)
        { 
           int temp= (columnTitle[i] - 'A' + 1);
            res =  temp + 26*res;
        }
       return res;
    }
};