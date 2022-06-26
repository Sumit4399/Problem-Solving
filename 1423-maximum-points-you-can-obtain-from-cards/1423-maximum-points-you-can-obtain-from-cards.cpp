class Solution {
public:
    
//    int maxScore(vector<int>& card, int k) {
        
//         vector<int> prefix;
//         int sum=0;
//         int n=card.size();
        
//         for(int i=0; i<n; i++)
//         {
//             sum+=card[i];
//             prefix.push_back(sum);
//         }
        
//         int res=0;
//         int temp;
//         for(int i=0;i<=k;i++) {
//             if(i==0) {
//                 if(prefix.size()-k-1==-1) {
//                     temp = prefix.back();
//                 }
//                 else{
//                     temp = prefix.back()-prefix[prefix.size()-k-1];
//                 }
//             }
//             else {
//                 temp = prefix[i-1] + prefix.back()-prefix[prefix.size()-1-(k-i)];
//             }
//             if(temp>res) {
//                 res = temp;
//             }
//         }
//         return res;       
//    }
    
    
    
    int maxScore(vector<int>& C, int K) {
        
        int total = 0;
        for (int i = 0; i < K; i++) total += C[i];
        int best = total;
        for (int i = K - 1, j = C.size() - 1; i>=0;  i--, j--)
            total += C[j] - C[i], best = max(best, total);
        return best;
    }
};