import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    static int n;
    static int m;
    static int[] arr;
    static boolean[] isused;

    static void func(int k) {
        if(k == m) {
            for (int i=0; i<m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for(int i=1; i<=n; i++) {
            if(!isused[i]) {
                isused[i] = true;
                arr[k] = i;
                func(k+1);
                isused[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n+1];
        isused = new boolean[n+1];
        for(int i=0; i<n+1; i++) {
            isused[i] = false;
        }

        func(0);
    }
}
