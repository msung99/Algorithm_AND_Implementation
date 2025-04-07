import java.util.*;



class Solution {
    List<Integer>[] winList = new ArrayList[102]; // 이긴 사람
    List<Integer>[] loseList = new ArrayList[102]; // 진 사람
    static boolean[] visited = new boolean[102];

    public int bfs(List<Integer>[] graph, int start, int n) {
        int count = 0;
        Arrays.fill(visited, false);
        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);
        visited[start] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : graph[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(next);
                    count++;
                }
            }
        }
        return count;
    }

    public int solution(int n, int[][] results) {
        for (int i = 0; i <= n; i++) {
            winList[i] = new ArrayList<>();
            loseList[i] = new ArrayList<>();
        }

        for (int[] result : results) {
            int winner = result[0];
            int loser = result[1];
            winList[winner].add(loser); // winner가 이긴 사람
            loseList[loser].add(winner); // loser가 진 사람
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int winCount = bfs(winList, i, n);
            int loseCount = bfs(loseList, i, n);

            if (winCount + loseCount == n - 1) {
                answer++;
            }
        }

        return answer;
    }

}