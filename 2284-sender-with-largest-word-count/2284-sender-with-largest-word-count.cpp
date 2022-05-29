class Solution {
public:
    
    int words(string &s)
    {
        int cn=0;
        for(char c : s)
        {
            if(c == ' ')
                cn++;
        }
        return cn+1;
    }

    string largestWordCount(vector<string>& mes, vector<string>& sen) {
        
        map<string, int> mp;
        for(int i=0; i<mes.size(); i++)
        {
            int co= words(mes[i]);
            mp[sen[i]]+= co;
        }
        int c=0;
        string res="";
        
        //iterating on map
        for(auto it= mp.begin(); it!=mp.end(); it++)
        {
            if(it->second >= c)
            {
                c= it->second;
                res= it->first;
            }
        }
        return res;
    }
    
    
//     int countWords(string &str){
        
//         int count = 0;
//         for(char ch:str)
//         {
//             if(ch == ' ') ++count;
//         }
//         return count+1;
//     }
    
//     string largestWordCount(vector<string>& messages, vector<string>& senders){
        
//         map<string, int> mp;
//         for(int i = 0; i<messages.size(); ++i)
//         {
//             int count = countWords(messages[i]);
//             mp[senders[i]]+=count;
//         }
        
//         string ans = "";
//         int count = 0;
//         for(auto it = mp.begin(); it!=mp.end(); ++it)
//         {
//             if(it->second >= count)
//             {
//                 count = it->second;
//                 ans = it->first;
//             }
//         }
//         return ans;
//     }
};