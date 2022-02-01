class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l=0;
        int r=size(arr)-1;
        int mid;
        while(l<=r)
        {
            mid=(l+(r-l)/2);
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
                r--;
            else
                l++;
        }
        
        return -1;
    }
};