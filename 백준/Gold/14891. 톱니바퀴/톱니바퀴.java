import java.util.*;

public class Main {
    static List<StringBuilder> board = new ArrayList<>();

    public static void move(int num, int dir) {
        int[] dirs = new int[4];
        num--;
        dirs[num] = dir;

        // 왼쪽으로 회전 전파
        for (int i = num; i > 0; i--) {
            if (board.get(i).charAt(6) == board.get(i - 1).charAt(2)) {
                break;
            }
            dirs[i - 1] = -dirs[i];
        }

        // 오른쪽으로 회전 전파
        for (int i = num; i < 3; i++) {
            if (board.get(i).charAt(2) == board.get(i + 1).charAt(6)) {
                break;
            }
            dirs[i + 1] = -dirs[i];
        }

        // 회전 적용
        for (int i = 0; i < 4; i++) {
            if (dirs[i] == 1) { // 시계 방향 회전
                rotateClockwise(i);
            } else if (dirs[i] == -1) { // 반시계 방향 회전
                rotateCounterClockwise(i);
            }
        }
    }

    public static void rotateClockwise(int index) {
        StringBuilder sb = board.get(index);
        char last = sb.charAt(7);
        sb.deleteCharAt(7);
        sb.insert(0, last);
    }

    public static void rotateCounterClockwise(int index) {
        StringBuilder sb = board.get(index);
        char first = sb.charAt(0);
        sb.deleteCharAt(0);
        sb.append(first);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 4; i++) {
            board.add(new StringBuilder(sc.next()));
        }

        int k = sc.nextInt();

        while (k-- > 0) {
            int num = sc.nextInt();
            int dir = sc.nextInt();
            move(num, dir);
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            if (board.get(i).charAt(0) == '1') {
                ans += (1 << i);
            }
        }

        System.out.println(ans);
        sc.close();
    }
}
