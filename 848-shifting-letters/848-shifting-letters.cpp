class Solution {
public:
    string shiftingLetters(string s, vector<int>& shift) {
        
        int n=s.size();
        vector<long long int> v(n, 0);
        v[n-1]= shift[n-1];
        for(int i=n-2; i>=0; i--)
        {
            v[i]= shift[i] + v[i+1];
        }
        
        for(int i=0; i<n; i++)
        {
            int inc= (s[i] - 'a' + v[i])%26;
            s[i]= 'a' + inc;
        }
        
        return s;
    }
};