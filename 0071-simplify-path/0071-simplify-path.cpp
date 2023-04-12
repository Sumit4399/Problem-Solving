class Solution {
public:
    string simplifyPath(string s) {
        
        string res;
        stack<string> st;
        
        for(int i=0; i<s.length(); i++)
        {
           if(s[i]== '/')
               continue;
            
            string temp;
            while(i< s.size() && s[i] != '/')
            {
                temp+= s[i];
                i++;
            }
            
            if(temp== ".")
                continue;
            
            else if(temp== "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);     
        }
        
        while(!st.empty())
        {
            res= "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size()==0)
            return "/";
        else
        return res;
    }
};