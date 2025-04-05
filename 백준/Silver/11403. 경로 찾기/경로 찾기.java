import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int n;
    static int[][] board;
    static boolean[] visited;

    static boolean dfs(int st, int en) {
        for(int i=0; i<n+1; i++) {
            visited[i] = false;
        }

        Stack<Integer> s = new Stack<>();
        s.add(st);

        while(!s.empty()) {
            int cur = s.peek();
            s.pop();

            if(visited[cur]) {
                continue;
            }

            if(cur != st) {
                visited[cur] = true;
            }

            for(int next=0; next<n; next++) {
                if(visited[next]) {
                    continue;
                }

                if(board[cur][next] == 1) {
                    if(next == en) {
                        return true;
                    }
                    s.add(next);
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        board = new int[n+1][n+1];
        visited = new boolean[n+1];

        for(int i=0; i<n; i++) {
            visited[i] = false;
            for(int j=0; j<n; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dfs(i, j)) {
                    System.out.print("1 ");
                } else {
                    System.out.print("0 ");
                }
            }
            System.out.println();
        }
    }
}
