class Solution {
public:
    int bagOfTokensScore(vector<int>& tok, int power) {
        
        sort(tok.begin(), tok.end());
        int high= tok.size()-1;
        int st=0;
        int sc=0;
        int res=0;
        
        while(st<=high)
        {
            if(tok[st] <= power)
            {
                power-= tok[st];
                st++;
                sc++;
                res= max(res, sc);
            }
            
            else if(sc>0)
            {
                sc--;
                power+= tok[high];
                high--;
            }
            
            else
            {
                break;
            }
        }
        return res;
    }
};