class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        
        int len = nums.length;
        int dp[][] = new int[len][len];
        int res = 0;
        HashMap<Long, ArrayList<Integer>> numMap = new HashMap<>();
        
        for(int i = 0; i < len; i++) {
            long cur = nums[i];
            ArrayList<Integer> mList = numMap.getOrDefault(cur, new ArrayList<>());
            mList.add(i);
            numMap.put(cur, mList);
        }
        
        for(int i = 0; i < len-1; i++) {
            for(int j = i + 1; j < len; j++) {
                //long diff = 1L * nums[j] - nums[i];
				//long prev = 1L * nums[i] - diff;
                long prev = 2L * nums[i] - nums[j];
                int tmpcnt = 0;
                if(numMap.containsKey(prev)) {
                    for(int pos : numMap.get(prev)) {
                        if(pos < i)
                            tmpcnt += dp[pos][i] + 1;
                        else
                            break;
                    }
                }
                
                res += dp[i][j] = tmpcnt;
            }
        }
        return res;
    }
}