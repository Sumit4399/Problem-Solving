class Solution {
public:
    
    int mod= 1e9+7;
    int maxArea(int hh, int ww, vector<int>& h, vector<int>& v) {
        
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        
        //horizontal
        vector<int> hei= {h[0]};
        for(int i=1; i<h.size(); i++)
        {
            hei.push_back(h[i]- h[i-1]);
        }
        hei.push_back(hh- h[h.size()-1]);
        
        //vertical
        vector<int> ver= {v[0]};
        for(int i=1; i<v.size(); i++)
        {
            ver.push_back(v[i]- v[i-1]);
        }
        ver.push_back(ww- v[v.size()-1]);
        
        long long int x= *max_element(hei.begin(), hei.end());
        long long int y= *max_element(ver.begin(), ver.end());
        
        return (int)(x%mod * y%mod);
    }
};