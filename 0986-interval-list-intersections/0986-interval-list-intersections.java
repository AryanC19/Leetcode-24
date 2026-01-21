class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int i=0;
        int j=0;
        int n=firstList.length;
        int m=secondList.length;

        List<int[]> ans=new ArrayList<>();

        while(i<n && j<m){

            int s1=firstList[i][0];
            int e1=firstList[i][1];

            int s2=secondList[j][0];
            int e2=secondList[j][1];
            //if intersecting

            int s3=-1,e3=-1;
            if(s1<=e2 && s2<=e1){
                if(s1<=s2 && e1<=e2){
                    s3=s2;
                    e3=e1;
                }else if(s2<=s1 && e2<=e1){
                    s3=s1;
                    e3=e2;
                }else if(s1<=s2 && e2<=e1){
                    s3=s2;
                    e3=e2;
                }else{
                    s3=s1;
                    e3=e1;
                }

                ans.add(new int[]{s3,e3});
            }
            // was wrapping this in else, and compating by s1, and s2. 
            // keep note on ir
            if(e1<=e2) i++;
            else j++;
            
        }

        return ans.toArray(new int[ans.size()][]);

    }
}