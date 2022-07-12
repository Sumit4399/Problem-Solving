class Solution {
public:
    
    bool canReach(vector<int>& arr, int curr) {
        
        if(curr<0 || curr>=size(arr) || arr[curr]<0)
            return false;
        
        if(arr[curr] == 0)
            return true;
        
        arr[curr] = arr[curr] * -1; //mark the index elements as visited
        
        return canReach(arr, curr + arr[curr]) || 
                canReach(arr, curr - arr[curr]);
    }
};