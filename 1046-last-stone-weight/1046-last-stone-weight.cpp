class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<size(stones); i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size()>1)
        {
           int x= pq.top();
           pq.pop();
            
           int y= pq.top();
           pq.pop();
            
            if(x!=y)
                pq.push(abs(y-x));
        }
        
        if(pq.size()==1)
            return pq.top();
        else
            return 0;
    }
};