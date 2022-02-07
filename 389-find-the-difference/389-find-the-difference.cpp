class Solution {
public:
    char findTheDifference(string s, string t) {
        
//         int s1= 0;
//         int s2= t[s.length()];
//         for(int i=0; i<s.length(); i++)
//         {
//             s1+= s[i];
//             s2+= t[i];
//         }
        
//         return char(abs(s1-s2));
//     }
        
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int i = 0;
		while(i < s.size()){
			if(s[i] != t[i]){
				return t[i];
			}
			i++;
		}
		return t[s.size()];
    }
};