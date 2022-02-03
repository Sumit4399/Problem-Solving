class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        // int n=nums1.size();
        // int count=0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         for(int k=0; k<n; k++){
        //             for(int l=0; l<n; l++){
        //                 if(nums1[i]+nums2[j]+nums3[k]+nums4[l]==0)
        //                 {
        //                     count++;
        //                 }
        //             }
        //         }
        //     }
        // }  
        // return count;
        
        
     //using hash-map
        
     unordered_map<int, int> m;
		for(int i = 0; i < nums1.size(); i++){
			for(int j = 0; j < nums2.size(); j++){
				m[nums1[i] + nums2[j]]++;
			}
		}
		int res = 0;
		for(int i = 0; i < nums3.size(); i++){
			for(int j = 0; j < nums4.size(); j++){
				if(m.find(-(nums3[i] + nums4[j])) != m.end()){
					res += m[-(nums3[i] + nums4[j])];
				}
			}
		}
		return res; 
        
        
    }
};