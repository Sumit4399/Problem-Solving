class Solution {
public:
    
     static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& box, int truck) {
        
        sort(box.begin(), box.end(), cmp);
        
        int res=0;
        for(auto it : box)
        {
            int x= min(it[0], truck);
            res+= x*it[1];
            truck-= x;

            if(truck==0)
                break;
        }
        return res;
    }
};