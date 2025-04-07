import java.util.*;

public class Main {
    static int n, w, l;
    static Queue<Integer> truck = new LinkedList<>();
    static int[] bridge = new int[1002];

    static boolean isBridgeEmpty() {
        for(int i=0; i<w; i++) {
            if(bridge[i] != 0) {
                return false;
            }
        }
        return true;
    }

    static int getCurBridgeTruckWeight() {
        int weight = 0;
        for(int i=0; i<w; i++) {
            weight += bridge[i];
        }
        return weight;
    }

    static int move() {
        int lastQuitTruckWeight = bridge[w-1];
        for(int i=w-1; i>0; i--) {
            bridge[i] = bridge[i-1];
        }
        bridge[0] = 0;
        return lastQuitTruckWeight;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); // 트럭의 수
        w = sc.nextInt(); // 다리의 길이
        l = sc.nextInt(); // 다리의 최대하중

        for(int i=0; i<n; i++) {
            int data = sc.nextInt(); // 트럭의 무게
            truck.add(data);
        }

        int ans = 0;
        do {
            ans++;
            int curWeight = getCurBridgeTruckWeight();
            int lastQuitTruckWeight = move();
            curWeight -= lastQuitTruckWeight;

            // curWeight + truck.peek() : move() 를 통해 트럭을 이동시키고 난 뒤의 현 시점에서 다리에 올려진 트럭 무게(curWeight) 에 새로운 트럭(truck.peek) 을 하나 추가했을 때 무게
            if(!truck.isEmpty() && curWeight + truck.peek() <= l) {
                bridge[0] = truck.peek();
                truck.remove();
            }
        } while(!isBridgeEmpty());

        System.out.println(ans);
    }
}
