class Pair{
    int a;
    int b;
}
class Solution {
    

    public int numIslands(char[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int[][] dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int islands=0;

        int[][] vis = new int[m][n];

        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){

                if(grid[i][j]=='1' &&  vis[i][j]==0){
                    Pair p= new Pair();
                    p.a=i;
                    p.b=j;
                    Queue<Pair> q= new LinkedList<>();
                    q.offer(p);
                    vis[i][j]=1;
                    islands++;
                    while(!q.isEmpty()){
                        Pair cur=q.peek();
                        q.poll();
                        int a=cur.a;
                        int b=cur.b;
                        for(int []dir: dirs ){
                            int na=a+dir[0];
                            int nb=b+dir[1];
                            if(na<m && nb <n && na>=0 && nb>=0 && grid[na][nb]=='1' && vis[na][nb]==0 ){
                                vis[na][nb]=1;
                                Pair np=new Pair();
                                np.a=na;
                                np.b=nb;
                                q.offer(np);
                            }
                        }
                    }                 
                }

            }
        }
        return islands;


    }
}