import java.util.ArrayList;
import java.util.Arrays;
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
    static int[] num;
    static StringBuilder sb = new StringBuilder();

    static void func(int k) {
        if(k == m) {
            for(int i=0; i<m; i++) {
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }

        int lastNum = 0;
        for(int i=0; i<n; i++) {
            if(num[i] != lastNum) {
                arr[k] = num[i];
                lastNum = num[i];
                func(k+1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[10];
        num = new int[n];

        for(int i=0; i<n; i++) {
            num[i] = sc.nextInt();
        }
        Arrays.sort(num);

        func(0);
        System.out.print(sb);
    }
}
