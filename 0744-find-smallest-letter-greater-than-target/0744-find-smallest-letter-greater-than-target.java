class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char ans= letters[0];
        int n=letters.length;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if((int) letters[mid] > (int) target){
                ans=letters[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
}