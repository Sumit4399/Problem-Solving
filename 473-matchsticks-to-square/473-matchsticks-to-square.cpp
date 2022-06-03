class Solution {
public:
    
//     int cnt(int i, int target, vector<int>& arr, vector<vector<int>>&dp){
//         if(target==0) return 1;
        
//         if(i==0){
//             return (arr[0]==target)?1:0;
//         }
        
//         if(dp[i][target]!=-1) return dp[i][target];
        
//         int take=0;
//         if(arr[i]<=target){
//             take=cnt(i-1, target-arr[i], arr, dp);
//         }
//         int nottake=cnt(i-1, target, arr, dp);
        
//         return dp[i][target]=take+nottake;
//     }
    
//     bool makesquare(vector<int>& m) {
//         int Tsum=0;
//         int n=m.size();
//         for(int i=0; i<n; i++){
//             Tsum+=m[i];
//         }
//         if(Tsum%4!=0) return false;
//         Tsum=Tsum/4;
//         vector<vector<int>>dp(n, vector<int>(Tsum+1, -1));
        
//         cout<<cnt(n-1, Tsum, m, dp)<<endl;
//         if(cnt(n-1, Tsum, m, dp)>=4){
//             return true;
//         }
//         else{
//             return false;
//         } 
        
//     }
    

    bool makesquare(vector<int> & matchsticks) {
        
        //sort the matchsticks elements into descending order, 
        //so that the matchsticks with larger value will be picked up early.
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<bool> vis(16, false);
       // memset(vis, false, sizeof(vis));
        
        int sum = 0;
        for (int i: matchsticks)
            sum += i;
        if (sum % 4)
            return false;
        
        int oneSideLength = sum / 4;
        int totalSides = 4;
        
        return canMakeSquare(vis, matchsticks, 0, oneSideLength, totalSides);
    }
    
    
    bool canMakeSquare(vector<bool> &vis, vector < int > & matchsticks, int currentSum, 
                       int oneSideLength, int totalSides, int idx = 0) {
        
        if (totalSides == 1) // This is the optimisation
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(vis, matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        
        for (int i = idx; i < size(matchsticks); i++)
        {
            if (!vis[i])
            {
                if (currentSum + matchsticks[i] <= oneSideLength)
                {
                    vis[i] = true;
                    if (canMakeSquare(vis, matchsticks, currentSum + matchsticks[i], 
                                      oneSideLength, totalSides, i + 1))
                        return true;
                    
                    vis[i] = false;
                }
            }
        }
        return false;
    }

};