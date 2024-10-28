import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


class Solution {
    List<Integer>[] adj_list = new ArrayList[20005];
    int[] dist = new int[20005];

    public int solution(int n, int[][] edge) {
        int answer = 0;

        for(int i=1; i<=n; i++) {
            dist[i] = -1;
        }

        for(int i=1; i<=n; i++) {
            adj_list[i] = new ArrayList<>();
        }

        for(int i=0; i<edge.length; i++) {
            for(int j=0; j<edge[i].length; j++) {
                int u = edge[i][0]; int v = edge[i][1];
                adj_list[u].add(v);
                adj_list[v].add(u);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        dist[1] = 0;

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int next : adj_list[cur]) {
                if(dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
            }
        }

        int mx = Integer.MIN_VALUE;
        for(int i=1; i<=n; i++) {
            if (mx < dist[i]) {
                mx = dist[i];
            }
        }

        for(int i=1; i<=n; i++) {
            if(dist[i] == mx) {
                answer++;
            }
        }

        return answer;
    }
}