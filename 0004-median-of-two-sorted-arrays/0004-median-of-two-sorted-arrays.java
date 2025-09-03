class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;

        int curr=-1, prev=-1;
        int cnt=0;
        int medianPointer=(n+m)/2;

        double ans=0;

        int l=0,r=0;

        while(cnt<=medianPointer){
            prev=curr;
            if(l<n && (r>=m || nums1[l]<=nums2[r])){
                curr=nums1[l];
                l++;
            }else{
                curr=nums2[r];
                r++;
            }
            cnt++;
        }

        if((n+m)%2==0){
            ans= (curr+prev)/2.0;
        }else{
            ans=curr;
        }
        return ans;
    }
}