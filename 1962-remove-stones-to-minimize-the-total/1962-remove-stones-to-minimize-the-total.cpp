class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int, vector<int>> pq;
        int total=0;
        for(int i=0; i<size(piles); i++)
        {
            total+= piles[i];
            pq.push(piles[i]);
        }
        
        while(k--)
        {
            int x= pq.top();
            int del= floor(x/2);
            pq.pop();
            total-= del;
            pq.push(x-del);
        }
        
        return total;
    }
};