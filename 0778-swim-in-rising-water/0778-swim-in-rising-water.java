class Solution {

    public int swimInWater(int[][] grid) {
        int n=grid.length;

        int [][] vis =new int[n][n];

        PriorityQueue<int[]> pq= new PriorityQueue<>((a,b)->a[0]-b[0]);

        pq.add(new int[]{grid[0][0],0,0});
        vis[0][0]=1;
        int ans=Integer.MIN_VALUE;


        while(!pq.isEmpty()){

            int[] p=pq.peek();
            pq.poll();
            int time=p[0];
            int i=p[1];
            int j=p[2];
            vis[i][j]=1;
            ans=Math.max(ans,time);
            if(i==n-1 && j==n-1) return ans;
            
            final int[][] dirs= {{0,1},{1,0},{-1,0},{0,-1}};
            
            for(int[] dir:dirs){
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(ni<n && nj<n && ni>=0 && nj>=0 && vis[ni][nj]!=1){
                    
                    pq.add(new int[]{grid[ni][nj],ni,nj});
                }
            }

        }
        return -1;
    }
}