class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n= s.size();
        int ans=0;
        if(n==0)
            return 0;
        
        unordered_set<char> st;
        int i=0, j=0;
        
        while(i<n)
        {
            if(st.count(s[i]) == 0)
            {
                st.insert(s[i]);
                int sz= st.size();
                ans= max(ans, sz);
                i++;
            }
            else
            {
                st.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};