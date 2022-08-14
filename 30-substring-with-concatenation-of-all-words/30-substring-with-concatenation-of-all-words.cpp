class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = words.size();
        int k = words[0].size();
        int len_substr = k*n;
        vector<int>indexes;
        
        if(len_substr > s.size())
            return indexes;
        
        map<string,int>mp,mp2;
        
        for(auto word: words)
            mp[word]++;
 
        int j;
        for(int i = 0; i<=s.size() - len_substr; i++)
        {
             mp2 = mp;
          
            for(j = i; j<i+len_substr;)
            {
                 string substr = s.substr(j,k);
             
                if(mp2.find(substr) == mp2.end())
                    break;
              
               if(mp2[substr] == 1)
                   mp2.erase(substr);
               
                else
                    mp2[substr]--;
                
                 j+=k;
            }
          
            if(j == i+ len_substr)
                indexes.push_back(i);  
        }
        
        return indexes;
       
    }
};