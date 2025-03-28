import java.util.Scanner;

public class Main {
    public static int res(int n, int r, int c) {
        if (n == 1) {
            return 1;
        }

        int half = n / 2;

        if (r < half && c < half) {
            return res(half, r, c);
        } else if (r < half && c >= half) {
            return half * half + res(half, r, c - half);
        } else if (r >= half && c < half) {
            return 2 * half * half + res(half, r - half, c);
        } else {
            return 3 * half * half + res(half, r - half, c - half);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        n = (1 << n);

        System.out.println(res(n, r, c) - 1);
        
        sc.close();
    }
}
