class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n= arr.size();
        vector<int> res(n, -1);
        
        for(int i=0; i<n-1; i++)
        {
            int maxi= *max_element(arr.begin()+i+1, arr.end());
            res[i]= maxi;
        }
        
        //res[n]= -1;
        return res;
    }
};