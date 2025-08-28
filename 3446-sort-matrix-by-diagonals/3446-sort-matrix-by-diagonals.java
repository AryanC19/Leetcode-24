import java.util.*;

class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        // bottom-left triangle + main diagonal: start from (i,0), i = n-1 .. 0, sort DESC
        for (int i = n - 1; i >= 0; i--) {
            int ti = i, tj = 0;
            List<Integer> temp = new ArrayList<>();
            while (ti < n && tj < n) {
                temp.add(grid[ti][tj]);
                ti++; tj++;
            }
            Collections.sort(temp, Collections.reverseOrder()); // non-increasing
            ti = i; tj = 0;
            for (int k = 0; k < temp.size(); k++) {
                grid[ti][tj] = temp.get(k);
                ti++; tj++;
            }
        }

        // top-right triangle: start from (0,j), j = 1 .. n-1, sort ASC
        for (int j = 1; j < n; j++) {
            int ti = 0, tj = j;
            List<Integer> temp = new ArrayList<>();
            while (ti < n && tj < n) {
                temp.add(grid[ti][tj]);
                ti++; tj++;
            }
            Collections.sort(temp); // non-decreasing
            ti = 0; tj = j;
            for (int k = 0; k < temp.size(); k++) {
                grid[ti][tj] = temp.get(k);
                ti++; tj++;
            }
        }

        return grid;
    }
}
