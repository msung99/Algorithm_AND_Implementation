import java.util.*;

public class Main {
    static int n, m;
    static int[][] board1 = new int[10][10];
    static int[][] board2 = new int[10][10];
    static List<int[]> wall = new ArrayList<>();
    static List<int[]> virus = new ArrayList<>();
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board1[i][j] = sc.nextInt();
                if (board1[i][j] == 0) {
                    wall.add(new int[]{i, j});
                }
                if (board1[i][j] == 2) {
                    virus.add(new int[]{i, j});
                }
            }
        }

        int ans = 0;
        int wallSize = wall.size();
        int[] brute = new int[wallSize];

        Arrays.fill(brute, wallSize - 3, wallSize, 1);

        do {
            copyBoard();
            for (int i = 0; i < wallSize; i++) {
                if (brute[i] == 1) {
                    int[] pos = wall.get(i);
                    board2[pos[0]][pos[1]] = 1;
                }
            }

            spreadVirus();

            int area = countSafeArea();
            ans = Math.max(ans, area);

        } while (nextPermutation(brute));

        System.out.println(ans);
        sc.close();
    }

    static void copyBoard() {
        for (int i = 0; i < n; i++) {
            System.arraycopy(board1[i], 0, board2[i], 0, m);
        }
    }

    static void spreadVirus() {
        Queue<int[]> q = new LinkedList<>();
        for (int[] v : virus) {
            q.offer(new int[]{v[0], v[1]});
        }

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board2[nx][ny] != 0) {
                    continue;
                }

                board2[nx][ny] = 2;
                q.offer(new int[]{nx, ny});
            }
        }
    }

    static int countSafeArea() {
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board2[i][j] == 0) {
                    area++;
                }
            }
        }
        return area;
    }

    static boolean nextPermutation(int[] arr) {
        int i = arr.length - 1;
        while (i > 0 && arr[i - 1] >= arr[i]) i--;

        if (i == 0) return false;

        int j = arr.length - 1;
        while (arr[i - 1] >= arr[j]) j--;

        swap(arr, i - 1, j);

        int k = arr.length - 1;
        while (i < k) {
            swap(arr, i++, k--);
        }

        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
