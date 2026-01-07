class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m=isWater.length;
        int n=isWater[0].length;
        int [][] dist=new int[m][n];

        Queue<int[]> queue=new LinkedList<>();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=-1;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    queue.add(new int[]{i,j});
                    dist[i][j]=0;
                }
            }
        }

        
        final int[][] dirs=new int[][]{{0,1},{1,0},{-1,0},{0,-1}};
        while(!queue.isEmpty()){

            int[] temp= queue.peek();
            queue.poll();
            int i=temp[0];
            int j=temp[1];
            
            for(int[] dir:dirs){
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni>=0 && nj>=0 && ni<m && nj<n && dist[ni][nj]==-1){
                    dist[ni][nj]=1+dist[i][j];
                queue.add(new int[]{ni,nj});
                }
            }
        }

        return dist;

    }
}