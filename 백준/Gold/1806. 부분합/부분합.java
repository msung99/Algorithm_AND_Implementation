import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n];

        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        int ans = Integer.MAX_VALUE;
        int sum = arr[0];
        int rt = 0;

        for(int lt=0; lt<n; lt++) {
            while(rt < n && sum < m) {
                rt++;
                if(rt != n) {
                    sum += arr[rt];
                }
            }

            if(rt == n) {
                break;
            }

            ans = Math.min(ans, rt-lt+1);
            sum -= arr[lt];
        }

        if(ans == Integer.MAX_VALUE) {
            ans = 0;
        }
        System.out.println(ans);
    }
}
