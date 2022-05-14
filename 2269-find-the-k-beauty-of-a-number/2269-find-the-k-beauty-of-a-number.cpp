class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string s= to_string(num);
        if(s.size()== k)
            return 1;
        
        int c=0;
        string temp;
    
        for(int i=0; i<=s.size()-k; i++)
        {
            temp= s[i];
            int n= k-1;
            int j= i+1;
            
            while(n>0)
            {
                temp+= s[j];
                j++;
                n--;
            }
            
            int d= stoi(temp);
            if(d!=0 && num%d == 0)
                c++;
            
        }
        
        return c;
    }
};