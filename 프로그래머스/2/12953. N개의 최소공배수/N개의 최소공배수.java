import java.util.Arrays;
// 최소공배수는 = (n1 * n2) / n1과 n2의 최소공약수

class Solution {

    // n1 과 n2 의 최대 공약수
    public int getGCD(int n1, int n2) {
        if(n1 % n2 == 0) {
            return n2;
        }
        return getGCD(n2, n1 % n2);
    }

    public int solution(int[] arr) {
        Arrays.sort(arr);

        // 최소 공배수
        for(int i=0; i<arr.length-1; i++) {
            int num = getGCD(arr[i+1], arr[i]);
            arr[i+1] = (arr[i] * arr[i+1]) / num;
        }

        return arr[arr.length-1];
    }
}