import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n;
    static int m;
    static List<Integer>[] light = new ArrayList[1002];
    static List<Integer>[] heavy = new ArrayList[1002];
    static boolean[] visited;

    static boolean bfs(int st, List<Integer>[] adj_list) {
        for(int i=1; i<=n; i++) {
            visited[i] = false;
        }

        Queue<Integer> q = new ArrayDeque<>();
        q.add(st);
        visited[st] = true;

        int cnt = 0;
        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int next : adj_list[cur]) {
                if(visited[next]) {
                    continue;
                }
                cnt++;
                visited[next] = true;
                q.add(next);
            }
        }

        int half = (n+1) / 2;
        int max = Integer.MIN_VALUE;

        if(cnt >= half) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        visited = new boolean[1002];

        for(int i=0; i<1002; i++) {
            heavy[i] = new ArrayList<>();
            light[i] = new ArrayList<>();
        }

        for(int i=0; i<m; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();
            heavy[u].add(v);
            light[v].add(u);
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(bfs(i, heavy) || bfs(i, light)) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
