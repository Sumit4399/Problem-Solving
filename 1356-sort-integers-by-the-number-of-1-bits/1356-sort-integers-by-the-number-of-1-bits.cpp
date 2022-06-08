class Solution {
public:
    
    static bool cmp(pair<int, int>&a, pair<int, int>&b){
        if(a.second<b.second) return true;
        if(a.second>b.second) return false;
        
        if(a.second==b.second){
            if(a.first<b.first) return true;
            
        }
        return false;
    }
    
    int Cbits(int n){
        int res=0;
        while(n>0){
            n=n&(n-1);
            res++;
        }
        return res;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
//         vector<int> res;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, 
//         greater<pair<int, int>>> pq;
        
//         for(int i=0; i<arr.size(); i++)
//         {
//             int c= __builtin_popcount(arr[i]);
//             pq.push({c, arr[i]});
//         }
        
//         while(!pq.empty())
//         {
//             int x= pq.top().second;
//             res.push_back(x);
//             pq.pop();
//         }
//         return res;
        
        vector<pair<int, int>>res;
        for(int i=0; i<arr.size(); i++){
            res.push_back({arr[i], Cbits(arr[i])});
        }
        
        sort(res.begin(), res.end(), cmp);
        arr.clear();
        for(auto x:res){
            arr.push_back(x.first);
        }
        
        return arr;
    }
};