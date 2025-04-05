import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int v, e;
    static List<Integer>[] adj_list = new ArrayList[20002];
    static int[] flag = new int[20002]; // -1: 아직 방문안함 / 1 또는 2로 구성

    static boolean solve() {
        for(int i=0; i<v+1; i++) {
            flag[i] = -1;
        }

        for(int i=1; i<=v; i++) {
            if(flag[i] != -1) {
                continue;
            }

            Queue<Integer> q = new ArrayDeque<>();
            q.add(i);
            flag[i] = 1;

            while(!q.isEmpty()) {
                int cur = q.poll();

                for(int next : adj_list[cur]) {
                    // next 가 이미 색칠되어 있는 경우
                    if(flag[next] != -1) {
                        if(flag[cur] == flag[next]) {
                            return false;
                        } else {
                            continue;
                        }
                    }

                    // flag[next] == -1 인 경우 (처음 방문하는 경우)
                    if(flag[cur] == 1) {
                        flag[next] = 2;
                    } else if(flag[cur] == 2) {
                        flag[next] = 1;
                    }
                    q.add(next);
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for(int i=0; i<20002; i++) {
            adj_list[i] = new ArrayList<>();
        }

        int t = sc.nextInt();
        for(int tt=0; tt<t; tt++) {
            v = sc.nextInt();
            e = sc.nextInt();

            for(int i=1; i<=v; i++) {
                adj_list[i].clear();
            }

            for(int i=0; i<e; i++) {
                int u, v;
                u = sc.nextInt();
                v = sc.nextInt();
                adj_list[u].add(v);
                adj_list[v].add(u);
            }

            if(solve()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
