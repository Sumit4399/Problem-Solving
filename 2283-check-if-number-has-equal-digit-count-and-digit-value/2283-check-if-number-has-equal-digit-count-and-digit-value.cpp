class Solution {
public:
    bool digitCount(string num) {
        
       unordered_map<int,int> mp;
        int n= num.length();
        
        for(auto it:num)
        {
            int x = it - '0';
            mp[x]++;
        }
        
        for(int i=0;i<n;i++)
        {
            int x = num[i] - '0';
            
            if(x == 0 && mp.find(i) != mp.end())
                return false;
            
            else if(mp[i] != x)
                return false;
        }
        return true;
    }
};