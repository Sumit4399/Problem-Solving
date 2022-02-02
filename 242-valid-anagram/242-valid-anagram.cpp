class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!= t.length())
            return false;
        
        int res=0;
        unordered_map<char,int> m;
        for(int j=0; j<t.length(); j++)
        {
            m[t[j]]++;
        }
         int count=m.size();//count variable to check when all the 
        //characters present in the map have frequencies zero,which
            //implies that an anagram is found.
        int k=t.length();//Window size.
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if(count==0)
                {
                    return true;
                }
                i++;
                j++;
            }
        }
        return false;

    }
};