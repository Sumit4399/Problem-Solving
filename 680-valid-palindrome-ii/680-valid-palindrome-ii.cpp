class Solution {
public:
//     bool validPalindrome(string s) {
        
//         int i=0;
//         int j= s.size()-1;
//         int c=0;
        
//         while(i<=j)
//         {
//             if(s[i]==s[j])
//             {
//                 i++;
//                 j--;
//             }
//             else
//             {
//                 if(c==0 && s[i]==s[j-1])
//                 {
//                     //i++;
//                     j--;
//                     c++;
//                 }
//                 else if(c==0 && s[i+1]==s[j])
//                 {
//                     i++;
//                     //j--;
//                     c++;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
    
    
    bool validPalindrome(string s) {
	int left = 0, right = s.length() - 1;
	while (left < right) {
		if (s[left] != s[right]) {
			return isPalin(s, left + 1, right) || isPalin(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}

bool isPalin(string s, int left, int right) {
	while (left < right) {
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}
};