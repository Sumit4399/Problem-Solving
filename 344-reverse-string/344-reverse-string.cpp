class Solution {
public:
    
    void rev(vector<char>& s, int l, int r){
        
        if(l>=r)
            return;
        
        else
        {
            swap(s[l++], s[r--]);
            rev(s, l, r);
        }
    }
    
    void reverseString(vector<char>& s) {
       
        rev(s, 0, s.size()-1);
    }
};