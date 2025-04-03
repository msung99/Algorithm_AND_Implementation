import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Solution {
    int[][] dist;
    int[] dx = {0, 1, 0, -1};
    int[] dy = {-1, 0, 1, 0};

    public int solution(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        dist = new int[n+1][m+1];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                dist[i][j] = -1;
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        dist[0][0] = 1;

        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if(board[nx][ny] == 0 || dist[nx][ny] != -1) {
                    continue;
                }
                q.add(new int[]{nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }

        return dist[n-1][m-1];
    }
}