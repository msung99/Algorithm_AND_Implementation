import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static List<List<Integer>> party = new ArrayList<>();

    static boolean isMatch(List<Integer> group, int person) {
        for(int i=0; i<group.size(); i++) {
            if(group.get(i) == person) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        Queue<Integer> q = new LinkedList<>();

        int t = sc.nextInt();
        for(int i=0; i<t; i++) {
            int data = sc.nextInt();
            q.add(data);
        }

        for(int i=0; i<m; i++) {
            int te;
            te = sc.nextInt();
            List<Integer> tmp = new ArrayList<>();
            for(int j=0; j<te; j++) {
                int data = sc.nextInt();
                tmp.add(data);
            }
            party.add(tmp);
        }

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int i=0; i<party.size(); i++) {
                if(isMatch(party.get(i), cur)) {
                    for(int person : party.get(i)) {
                        q.add(person);
                    }
                    party.remove(i);
                }
            }
        }
        System.out.println(party.size());
    }
}
