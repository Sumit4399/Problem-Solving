class Solution {
public:
    bool canBeEqual(vector<int>& tar, vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        sort(tar.begin(), tar.end());
        
        if(arr==tar)
            return true;
        else 
            return false;
        
    }
};