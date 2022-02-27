class Solution {
public:
    
    //func to calculate trips covered in given time frame 
    long long tripsTaken(vector<int>& time, long long mid){
        
        long long cnt=0;
        for(auto it: time)
        {
            cnt+= mid/it;
        }
        return cnt;
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long low=0, high=1e14;
        //here maximum high time= time*totaltrips= 1e7*1e7(look the constraints)
        long long res= high;
        
        while(low<=high)
        {
            //because right shift (>>) operator works faster than '/'
            //both will work fine
            long long mid= (low+high) >> 1;
            //long long mid= (low+high) / 2;
            
            if(tripsTaken(time, mid) >= totalTrips)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low= mid+1;  
            } 
        }
        return res;
    }
};