class Solution {
public:
    int convertTime(string current, string correct) {
        
//         string h1;
//         h1= curr[0]+ curr[1];
//         string m1;
//         m1= curr[3] + curr[4];
        
//         string h2;
//         h2= cor[0] + cor[1];
//         string m2;
//         m2= cor[3] + cor[4];
        
//         int s1= (int)h1;
//         int e1= (int)m1;
        
//         int s2= (int)h2;
//         int e2= (int)m2;
        
        int s1=(int)(current[0]*10+current[1]);
        int s2=(int)(correct[0]*10+correct[1]);
        int e1=(int)(current[3]*10+current[4]);
        int e2=(int)(correct[3]*10+correct[4]);
        
        int hour=0;
        int mint=0;
        int res=0;
        
        //case-1(when m1>m2)
        if(e1>e2)
        {
            hour= s2-s1-1;
            mint= (60-e1) + e2;
            res=hour;
            
            while(mint>0)
            {
                if(mint>=15)
                {
                    res+= mint/15;
                    mint= mint%15;
                }
                else if(mint>=5 && mint<15)
                {
                    res+= mint/5;
                    mint = mint %5;
                }
                else
                {
                    res+= mint/1;
                    mint= mint%1;
                }
            }
        }
        
        //case-2(when m1<m2)
        else if(e1<e2)
        {
            hour= s2-s1;
            mint= e2-e1;
            res=hour;
            
            while(mint>0)
            {
                if(mint>=15)
                {
                    res+= mint/15;
                    mint= mint%15;
                }
                else if(mint>=5 && mint<15)
                {
                    res+= mint/5;
                    mint = mint %5;
                }
                else
                {
                    res+= mint/1;
                    mint= mint%1;
                }
            }
        }
        
        else
        {
            hour= s2-s1;
            res=hour;
        }
        
        return res;
    }
};