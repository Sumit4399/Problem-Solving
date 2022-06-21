class Solution {
public:
    int minMoves(vector<int>& arr) {
        
        int n= arr.size();
        int mini= *min_element(arr.begin(), arr.end());
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans+= arr[i]- mini;
        }
        return ans;
    }
};