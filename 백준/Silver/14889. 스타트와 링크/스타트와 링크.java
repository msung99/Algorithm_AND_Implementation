import java.util.Scanner;

public class Main {
    static int n;
    static int[][] board;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;

    static void func(int k, int st) {
        if(k == n/2) { // 팀 조합이 완성된 경우
            diff(); // 방문한 팀과 방문하지 않음 팀을 나누어 각 팀의 점수를 구하고 최솟값을 찾는다.
            return;
        }

        for(int i=st; i<n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                func(k+1, i+1);
                visited[i] = false;
            }
        }
    }

    static void diff() {
        int teamStart = 0;
        int teamLink = 0;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(visited[i] && visited[j]) {
                    teamStart += board[i][j];
                    teamStart += board[j][i];
                }

                else if(!visited[i] && !visited[j]) {
                    teamLink += board[i][j];
                    teamLink += board[j][i];
                }
            }
        }

        int val = Math.abs(teamStart - teamLink);
        if(val == 0) {
            System.out.println(val);
            System.exit(0);
        }

        answer = Math.min(val, answer);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        board = new int[n][n];
        visited = new boolean[n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        func(0, 0);
        System.out.println(answer);
    }
}
