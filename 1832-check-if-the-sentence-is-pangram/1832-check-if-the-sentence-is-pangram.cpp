class Solution {
public:
    bool checkIfPangram(string str) {
        
        unordered_set<char> st;
        for(int i=0; i<str.size(); i++)
        {
            st.insert(str[i]);
        }
        
        if(st.size()==26)
            return true;
        else
            return false;
    }
};