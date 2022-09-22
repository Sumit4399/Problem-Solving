class Solution {
public:
    string reverseWords(string s) {
        
        string temp="";
        vector<string> v;
        string res="";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=' ')
            {
                temp+= s[i];
            }
            else
            {
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
                temp="";
            }
        }
        
        reverse(temp.begin(), temp.end());
        v.push_back(temp);
        
        for(int i=0; i<v.size()-1; i++)
        {
            res+= v[i]+" ";
        }
        
        res+= v.back();
        
        return res;
    }
};