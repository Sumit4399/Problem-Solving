typedef long long int lld;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        
//         lld valley = 0;
//         lld peek = 0;
//         lld offset = 0;
        
//         for (int v : differences) {
//             offset += v;
//             if (offset > peek) {
//                 peek = offset;
//             }
//             if (offset < valley) {
//                 valley = offset;
//             }
//         }
//         int cnt = (int)((upper - peek) - (lower - valley) + 1);
//         if (cnt <= 0) {
//             return 0; 
//         }
//         return cnt;
        
        
        long a = 0, ma = 0, mi = 0;
        for (int d: differences) {
            a += d;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        return max(0L, (upper - lower) - (ma - mi) + 1);
    }
};