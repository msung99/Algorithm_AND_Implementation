import java.util.*;

public class Main {
    static List<Integer>[] adjList;
    static int[] dist;
    static int[] score;
    static int n;

    public static void bfs(int st) {
        Queue<Integer> q = new LinkedList<>();
        Arrays.fill(dist, -1);
        q.offer(st);
        dist[st] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int next : adjList[cur]) {
                if (dist[next] != -1) {
                    continue;
                }
                dist[next] = dist[cur] + 1;
                q.offer(next);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        adjList = new ArrayList[n + 1];
        dist = new int[n + 1];
        score = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            adjList[i] = new ArrayList<>();
        }

        while (true) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            if (u == -1 && v == -1) {
                break;
            }
            adjList[u].add(v);
            adjList[v].add(u);
        }

        for (int i = 1; i <= n; i++) {
            bfs(i);
            score[i] = Arrays.stream(dist, 1, n + 1).max().getAsInt();
        }

        int minValue = Arrays.stream(score, 1, n + 1).min().getAsInt();
        List<Integer> person = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (score[i] == minValue) {
                person.add(i);
            }
        }

        System.out.println(minValue + " " + person.size());
        for (int p : person) {
            System.out.print(p + " ");
        }

        sc.close();
    }
}
