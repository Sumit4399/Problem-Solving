// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) {
	    
	    int res=0;
        unordered_map<char,int> m;
        for(int j=0; j<p.length(); j++)
        {
            m[p[j]]++;
        }
         int count=m.size();//count variable to check when all the 
        //characters present in the map have frequencies zero,which
            //implies that an anagram is found.
        int k=p.length();//Window size.
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
                    res++;
               if(m.find(s[i])!=m.end())//while sliding the window check if that 
                   //character is present in the map then increase it's frequency
                   //by one as we have decreased the frequency of that character 
                   //when it was first encountered while traversing the window.
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return res;
 
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends