import java.util.LinkedList;
import java.util.Queue;

class Solution {
    boolean[] visited = new boolean[202];
    int[][] board = new int[202][202];

    void bfs(int st, int n) {
        Queue<Integer> q = new LinkedList<>();
        q.add(st);

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int next=0; next<n; next++) {
                if(visited[next] || board[cur][next] == 0) {
                    continue;
                }

                visited[next] = true;
                q.add(next);
            }
        }
    }

    public int solution(int n, int[][] boardTmp) {
        for(int i=0; i<n; i++) {
            visited[i] = false;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = boardTmp[i][j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                bfs(i, n);
                ans++;
            }
        }
        return ans;
    }
}