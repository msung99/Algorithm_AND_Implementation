import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


class Solution {
    static Map<Integer, Point> map = new HashMap<>();
    static int[] leftPoint = {4, 1};
    static int[] rightPoint = {4, 3};
    static List<Integer> leftNum = List.of(1, 4, 7);
    static List<Integer> rightNum = List.of(3, 6, 9);

    public String solution(int[] numbers, String hand) {
        init();
        String answer = "";

        for(int number : numbers) {
            if(leftNum.contains(number)) {
                leftPoint[0] = map.get(number).x;
                leftPoint[1] = map.get(number).y;
                answer += "L";
            }

            else if(rightNum.contains(number)) {
                rightPoint[0] = map.get(number).x;
                rightPoint[1] = map.get(number).y;
                answer += "R";
            }

            else {
                if(isLeftNearDist(number, hand)) {
                    leftPoint[0] = map.get(number).x;
                    leftPoint[1] = map.get(number).y;
                    answer += "L";
                } else {
                    rightPoint[0] = map.get(number).x;
                    rightPoint[1] = map.get(number).y;
                    answer += "R";
                }
            }
        }
        return answer;
    }

    public boolean isLeftNearDist(int number, String hand) {
        Point target = map.get(number);
        int leftDist = Math.abs(target.x - leftPoint[0]) + Math.abs(target.y - leftPoint[1]);
        int rightDist = Math.abs(target.x - rightPoint[0]) + Math.abs(target.y - rightPoint[1]);

        if(leftDist < rightDist) {
            return true;
        }

        else if(leftDist > rightDist) {
            return false;
        }

        else {
            if(hand.equals("left")) {
                return true;
            } else {
                return false;
            }
        }
    }

    public void init() {
        map.put(0, new Point(4, 2));
        map.put(1, new Point(1, 1));
        map.put(2, new Point(1, 2));
        map.put(3, new Point(1, 3));
        map.put(4, new Point(2, 1));
        map.put(5, new Point(2, 2));
        map.put(6, new Point(2, 3));
        map.put(7, new Point(3, 1));
        map.put(8, new Point(3, 2));
        map.put(9, new Point(3, 3));
    }

    public class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }
}