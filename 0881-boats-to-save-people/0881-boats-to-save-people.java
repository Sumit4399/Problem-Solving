class Solution {
    public int numRescueBoats(int[] people, int limit) {
        
        Arrays.sort(people);
        int cnt=0;
        
        int l=0;
        int r=people.length -1;
        
        while(l<=r)
        {
            int sum= people[l] + people[r];
            
            //1st case
            if(sum<=limit)
            {
                cnt++;
                l++;
                r--;
            }
            
            //2nd case
            else
            {
                cnt++;
                r--;
            }
        }
        return cnt;
    }
}