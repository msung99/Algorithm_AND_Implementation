import java.util.Scanner;

public class Main {
    static int[][] board;
    static int minusOne = 0, zero = 0, one = 0;

    public static void func(int n, int startX, int startY) {
        int color = board[startX][startY];

        if (n == 1) {
            if (color == -1) {
                minusOne++;
            } else if (color == 0) {
                zero++;
            } else if (color == 1) {
                one++;
            }
            return;
        }

        boolean isSameArea = true;
        for (int i = startX; i < startX + n; i++) {
            for (int j = startY; j < startY + n; j++) {
                if (board[i][j] != color) {
                    isSameArea = false;
                    break;
                }
            }
            if (!isSameArea) break;
        }

        if (isSameArea) {
            if (color == -1) {
                minusOne++;
            } else if (color == 0) {
                zero++;
            } else if (color == 1) {
                one++;
            }
        } else {
            int size = n / 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    func(size, startX + size * i, startY + size * j);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        board = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        func(n, 0, 0);

        System.out.println(minusOne);
        System.out.println(zero);
        System.out.println(one);
        
        sc.close();
    }
}
