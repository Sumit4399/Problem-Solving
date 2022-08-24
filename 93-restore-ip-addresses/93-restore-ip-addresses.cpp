class Solution {
public:
    
    bool valid(string s){
        
        if(s[0] == '0')
            return false;
        
        int val= stoi(s);
        return val<=255;
    }
    
    void helper(string s, int i, int pat, string temp, vector<string> &res){
        
        if(i==s.length() || pat==4)
        {
            if(i==s.length() && pat==4)
            {
                res.push_back(temp.substr(0, temp.length()-1));
            }
            return;
        }
        
        helper(s, i+1, pat+1, temp+s.substr(i, 1) + ".", res); //if we take till (i+1) element
        
        if(i+2 <= s.length() && valid(s.substr(i, 2))) 
            helper(s, i+2, pat+1, temp+s.substr(i, 2)+ ".", res); //if we take till (i+2) element
        
        if(i+3 <= s.length() && valid(s.substr(i, 3)))
            helper(s, i+3, pat+1, temp+s.substr(i, 3)+".", res); //if we take till (i+3) element
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        //string temp="";
        helper(s, 0, 0, "", res);
        return res;
    }
};