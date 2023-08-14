class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        int n= nums.length;
        
        PriorityQueue<Integer> pq= new PriorityQueue<Integer>((a,b)-> b-a);
        for(int i=0; i<n; i++)
        {
            pq.add(nums[i]);
        }
        
        while(k-1>0)
        {
            // System.out.println(pq.peek());
            pq.poll();
            k--;
        }
        
        return pq.peek();
    }
}