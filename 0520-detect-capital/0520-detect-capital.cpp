class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n=word.size();
        int cap=0;
        int small=0;
        
        for(int i=0; i<word.size(); i++)
        {
            if(isupper(word[i]))
                cap++;
            else
                small++;
        }
        
        if(isupper(word[0]) && (small==n-1))
            return true;
        else if(cap==0 && (small>0))
            return true;
        else if((cap>0) && small==0)
            return true;
        else
            return false;
    }
};