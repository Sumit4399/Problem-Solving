class Solution {
public:
    int furthestBuilding(vector<int>& h, int bri, int lad) {
        
        int diff=0;
        int i=0;
        priority_queue<int> pq;
        
        for(i=0; i<h.size()-1; i++)
        {
            diff= h[i+1]- h[i];
            if(diff<=0)
            {
                continue;
            }
            
            //use bricks
            bri= bri- diff;
            pq.push(diff);
            
            //restore bricks if it becomes negative
            if(bri<0)
            {
                bri+= pq.top();
                pq.pop();
                lad--;
            }
            
            if(lad<0)
                break;
            
        }
        
        return i;
    }
};