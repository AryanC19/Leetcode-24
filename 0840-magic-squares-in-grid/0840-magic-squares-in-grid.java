class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int magicSquares=0;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                boolean invalidSquare=false;
                HashSet<Integer> st=new HashSet<>();
                System.out.println("----------");

                for(int k=i;k<Math.min(i+3,n);k++){
                    for(int l=j;l<Math.min(j+3,m);l++){
                        System.out.print(grid[k][l]+",");
                        if(st.contains(grid[k][l]) || grid[k][l] <=0 || grid[k][l] >=10 ) {
                            invalidSquare=true;
                        }
                        st.add(grid[k][l]);
                    }
                    System.out.println();
                }
                System.out.println("----------");

                if(invalidSquare==true) continue;

                if(i==1 && j==0) System.out.println("I made it 1");

                int sumPrev=-1;

                //checking rows
                boolean rowSame=true;
                for(int k=i;k<Math.min(i+3,n);k++){
                    int sumCurr=0;
                    for(int l=j;l<Math.min(j+3,m);l++){
                        sumCurr+=grid[k][l];
                    }
                    if(sumPrev==-1) sumPrev=sumCurr;
                    else if(sumPrev!=-1 && sumPrev!=sumCurr){
                        rowSame=false;
                        break;
                    }
                }
                if(rowSame==false) continue;
                if(i==1 && j==0) System.out.println("I made it 2");
               


                //checking columns
                boolean colSame=true;
                for(int l=j;l<Math.min(j+3,m);l++){
                    int sumCurr=0;
                    for(int k=i;k<Math.min(i+3,n);k++){
                        sumCurr+=grid[k][l];
                    }
                    if(sumPrev!=sumCurr){
                        colSame=false;
                        break;
                    }
                }
                if(colSame==false) continue;
                if(i==1 && j==0) System.out.println("I made it 3");
                

                //checking diagonals
                boolean diagSame=true;
                int ld_k=i;
                int ld_l=j;
                int ld_sumCurr=0;
                while(ld_k<Math.min(i+3,n) && ld_l< Math.min(j+3,m)){
                    ld_sumCurr+=grid[ld_k][ld_l];
                    ld_k++;
                    ld_l++;

                }
                if(sumPrev!=ld_sumCurr){
                    continue;
                }
               if(i==1 && j==0) System.out.println("I made it 4");

                int rd_k=i+2;
                int rd_l=j;
                int rd_sumCurr=0;
                int cnt_rd=0;
                while(cnt_rd !=3 && rd_k<n && rd_k>=Math.max(rd_k-2,0) && rd_l< Math.min(rd_l+3,m)){
                    System.out.println("rd_k,"+rd_k);
                    System.out.println("rd_l,"+rd_k);
                    rd_sumCurr+=grid[rd_k][rd_l];
                    rd_k--;
                    rd_l++;
                    cnt_rd++;
                }
                if(i==1 && j==0) {
                    System.out.println("sumPrev,"+sumPrev);
                    System.out.println("rd_sumCurr,"+rd_sumCurr);
                }
                if(sumPrev!=rd_sumCurr){
                    continue;
                }
                if(i==1 && j==0) System.out.println("I made it 5");
                magicSquares++;
                
            }
        }
        
        return magicSquares;
    }
}