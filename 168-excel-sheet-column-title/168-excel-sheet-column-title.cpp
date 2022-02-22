class Solution {
public:
    string convertToTitle(int n) {
        
        //string res="";
        string ans;
	while(n)
    {
		n= n-1;
		ans=(char)(n%26+'A')+ ans;
		n/=26;
	}
	return ans;
    }
};