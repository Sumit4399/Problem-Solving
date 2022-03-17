class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        int c=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                st.push(c);
                c=0;
            }
            else
            {
                c= st.top() + max(2*c, 1);
                st.pop();
            }
        }
        return c;
    }
};