class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> st;
        int res = 0;
        long long x=1, y=1;
        
        for(int i = 0;i<n;i++)
        {
           if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
           {

                cout<<i<<" ";
                if(!st.empty())
                {
                    x = st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    y = st.top();
                    st.pop();
                }
                char a = tokens[i][0];
                long long temp;
                if(a == '+')
                    temp = y + x;
                else if(a == '-')
                     temp =  y - x;
                else if(a == '*')
                    temp = y * x;
                else
                   temp = y/x;
                st.push(temp);
           }
            else {
                int t = stoi(tokens[i]);
                st.push(t);
            }
        }
        return st.top();
    }
};