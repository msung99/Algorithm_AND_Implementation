import java.util.LinkedList;
import java.util.Queue;

class Solution {
    int[][] board = new int[201][201];
    boolean[] visited = new boolean[201];

    public void bfs(int st, int n) {
        Queue<Integer> q = new LinkedList<>();
        q.add(st);

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int next=0; next<n; next++) {
                if(visited[next]) {
                    continue;
                }

                if(board[cur][next] == 0) {
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

        for(int i=0; i<boardTmp.length; i++) {
            for(int j=0; j<boardTmp.length; j++) {
                board[i][j] = boardTmp[i][j];
            }
        }

        int answer = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                bfs(i, n);
                answer++;
            }
        }
        return answer;
    }
}