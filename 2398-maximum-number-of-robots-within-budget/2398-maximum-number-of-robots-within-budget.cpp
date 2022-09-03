class Solution {
public:
    int maximumRobots(vector<int>& chag, vector<int>& run, long long bud) {
        
        int maxi= INT_MAX;
        multiset<long long, greater<long long>> st;
        int res=0;
        int i=0;
        int j=0;
        long long sum=0;
        int n= chag.size();
        
        while(i<n && j<n)
        {
            st.insert(chag[j]);
            sum+= run[j];
            auto itr= st.begin();
            int x= *itr;
            
            if((x + (j-i+1)*sum) <= bud)
            {
                res= max(res, j-i+1);
            }
            
            else
            {
                while(i<j)
                {
                    st.erase(st.find(chag[i]));
                    sum-= run[i];
                    auto itr= st.begin();
                    x= *itr;
                    
                    if((x + (j-i)*sum) <= bud)
                    {
                        res= max(res, j-i);
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
        }
        
        return res;
    }
};