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
        Arrays.sort(arr);

        int rt = 0;
        int ans = Integer.MAX_VALUE;

        for(int lt=0; lt<n; lt++) {
            while(rt < n && arr[rt] - arr[lt] < m) {
                rt++;
            }

            if(rt == n) {
                break;
            }

            ans = Math.min(ans, arr[rt] - arr[lt]);
        }

        System.out.println(ans);
    }
}
