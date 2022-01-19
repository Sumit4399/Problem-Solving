class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n= cost.size();
        int t[n];
        
        for(int i=0; i<n; i++)
        {
            if(i<2)
                t[i]=cost[i];
            else
                t[i]= cost[i]+ min(t[i-1], t[i-2]);
        }
        return min(t[n-1], t[n-2]);
    }
    
    
    
    //o(1) time solution
    // Bottom up computation - O(n) time, O(1) space
//     public int minCostClimbingStairs(int[] cost) {
// 	int n = cost.length;
// 	int first = cost[0];
// 	int second = cost[1];
// 	if (n<=2) return Math.min(first, second);
// 	for (int i=2; i<n; i++) {
// 		int curr = cost[i] + Math.min(first, second);
// 		first = second;
// 		second = curr;
// 	}
// 	return Math.min(first, second);
// }
};