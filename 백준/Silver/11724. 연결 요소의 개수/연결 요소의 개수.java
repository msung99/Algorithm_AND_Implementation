import java.util.*;

public class Main {
    static int n, m;
    static List<Integer>[] adjList;
    static boolean[] visited;

    public static void bfs(int x) {
        Queue<Integer> q = new LinkedList<>();
        visited[x] = true;
        q.offer(x);

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int neighbor : adjList[cur]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.offer(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        adjList = new ArrayList[n + 1];
        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adjList[u].add(v);
            adjList[v].add(u);
        }

        int area = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                area++;
                bfs(i);
            }
        }

        System.out.println(area);
        sc.close();
    }
}
