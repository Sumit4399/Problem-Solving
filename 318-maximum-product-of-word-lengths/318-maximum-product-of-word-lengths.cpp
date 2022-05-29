class Solution {
public:
    
//     bool check(string s1, string s2){
        
//         map<char, int> mp;
        
//         for (int i = 0; i < s1.length(); i++)
//             mp[s1[i]]++;

//         for (int i = 0; i < s2.length(); i++)
//             if (mp[s2[i]] > 0)
//                 return true;
        
//         return false;
// }
    
//     int maxProduct(vector<string>& w) {
        
//         int mn= 0;
//         for(int i=0; i<w.size()-1; i++)
//         {
//             for(int j=0; j<w.size(); j++)
//             {
//                 if(check(w[i], w[j]) == false)
//                 {
//                     int x= w[i].size()*w[j].size();
//                     mn= max(mn, x);
//                 }
//             }
//         }
//         return mn;
//     }
    
    
    int maxProduct(vector<string>& words) {
        
	int n = size(words), ans = 0;
	vector<bitset<26> > chars(n);
	for(int i = 0; i < n; i++)
    {
		for(auto& ch : words[i])  // map the letters to 1 if it occurs in the word
			chars[i][ch - 'a'] = 1;
		// now check with all other words and if there's no common letter, then update ans	
		for(int j = 0; j < i; j++)
			if(!checkCommon(chars[i], chars[j])) 
				ans = max(ans, int(size(words[i]) * size(words[j])));
	}   
	return ans;
}
    
// Returns true if there's a common letter between bitset of two words
bool checkCommon(bitset<26>& a, bitset<26>& b) {
    
	for(int i = 0; i < 26; i++) if (a[i] && b[i]) 
        return true;
    
	return false;
}
    
};