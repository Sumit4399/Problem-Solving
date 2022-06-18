class Solution {
public:
    
    void check(int idx, vector<int> v, int &res)
    {
        if(idx== v.size())
        {
            res++;
            return;
        }
        
        for(int i=idx; i<v.size(); i++)
        {
            if((idx+1)%v[i]==0 || v[i]%(idx+1)==0)
            {
                swap(v[i], v[idx]);
                check(idx+1, v, res);
                swap(v[i], v[idx]);
            }
        }
    }
    
    int countArrangement(int n) {
        
        int res=0;
        vector<int> v;
        for(int i=1; i<=n ;i++)
        {
            v.push_back(i);
        }
        
        check(0, v, res);
        return res;
    }
};