import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int n, m;
    static List<Integer>[] adj_list = new ArrayList[102];
    static boolean[] visited = new boolean[102];

    static void bfs(int st) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(st);
        visited[st] = true;

        int ans = 0;
        while(!q.isEmpty()) {
            int cur = q.poll();
            ans++;

            for(int next : adj_list[cur]) {
                if(visited[next]) {
                    continue;
                }
                visited[next] = true;
                q.add(next);
            }
        }
        System.out.println(ans-1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        visited = new boolean[102];

        for(int i=0; i<102; i++) {
            adj_list[i] = new ArrayList<>();
            visited[i] = false;
        }

        for(int i=0; i<m; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();
            adj_list[u].add(v);
            adj_list[v].add(u);
        }

        bfs(1);
    }
}
