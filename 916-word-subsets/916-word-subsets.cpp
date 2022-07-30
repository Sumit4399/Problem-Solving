class Solution {
public:
    
    vector<int> count(string &word){
        
        vector<int> cnt(26);
        for(char c : word)
        {
            cnt[c- 'a']++;
        }
        return cnt;
    }
    
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        
        vector<int> temp(26), cnt(26);
        int i;
        
        for(string a : w2)
        {
            temp= count(a);
            for(i=0; i<26; i++)
            {
                cnt[i] = max(cnt[i], temp[i]);
            }
        }
        
        vector<string> res;
        for(string b : w1)
        {
            temp= count(b);
            for(i=0; i<26; i++)
            {
                if(temp[i] < cnt[i])
                    break;
            }
            if(i==26)
                res.push_back(b);
        }
        
        return res;
    }
};