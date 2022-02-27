class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int c=0;
        
        for(auto & word:words)
            if(word.find(pref)==0)
                c++;
        
        return c;
    }
};