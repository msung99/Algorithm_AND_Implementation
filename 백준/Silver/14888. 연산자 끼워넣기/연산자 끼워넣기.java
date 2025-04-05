import java.awt.Point;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int n;
    static int[] arr;
    static int[] oper = new int[4];
    static int maxValue = Integer.MIN_VALUE;
    static int minValue = Integer.MAX_VALUE;

    static void func(int k, int cur) {
        if(k == n) {
            maxValue = Math.max(maxValue, cur);
            minValue = Math.min(minValue, cur);
            return;
        }

        for(int i=0; i<4; i++) {
            if(oper[i] > 0) {
                oper[i]--;

                if(i == 0) {
                    func(k+1, cur + arr[k]);
                } else if(i == 1) {
                    func(k+1, cur - arr[k]);
                } else if(i == 2) {
                    func(k+1, cur * arr[k]);
                } else if(i == 3) {
                    func(k+1, cur / arr[k]);
                }
                oper[i]++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        arr = new int[n];
        oper = new int[4];

        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        for(int i=0; i<4; i++) {
            oper[i] = sc.nextInt();
        }

        func(1, arr[0]);
        System.out.println(maxValue);
        System.out.println(minValue);
    }
}
