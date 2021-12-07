class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map <int, int> m;
        map <int, int> check;

        for(auto i : arr)
            m[i]++;

        for(auto i : m)
        {
            if(check[i.second] == 1)
                return false;
            check[i.second]++;
        }
        return true;
    }
};