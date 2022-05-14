class Solution {
public:
    string removeDuplicates(string s) {
        
       stack<char> res;
        for(char c : s)
        {
            if(res.size() && c== res.top())
                res.pop();
            else
                res.push(c);
        }
        
        
        string ans={};
        while(!res.empty())
        {
            ans+= res.top();
            res.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};