import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m, st;
    static List<Integer>[] adj_list = new ArrayList[1002];
    static boolean[] visited = new boolean[1002];

    static void dfs(int cur) {
        visited[cur] = true;
        System.out.print(cur + " ");

        for(int next : adj_list[cur]) {
            if(visited[next]) {
                continue;
            }
            dfs(next);
        }
    }

    static void bfs(int st) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(st);
        visited[st] = true;

        while(!q.isEmpty()) {
            int cur = q.poll();
            System.out.print(cur + " ");

            for(int next : adj_list[cur]) {
                if(visited[next]) {
                    continue;
                }
                visited[next] = true;
                q.add(next);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        st = sc.nextInt();
        for(int i=0; i<1002; i++) {
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
        
        for(int i=1; i<=n; i++) {
            adj_list[i].sort(null);
        }

        dfs(st);
        System.out.println();

        for(int i=0; i<1002; i++) {
            visited[i] = false;
        }

        bfs(st);
    }
}
