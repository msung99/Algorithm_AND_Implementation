import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    static Set<Integer> numbers = new HashSet<>();
    static boolean[] isused = new boolean[10];

    void func(int k, String number, String input) {
        if(k  == input.length()) {
            return;
        }

        for(int i=0; i<input.length(); i++) {
            if(!isused[i]) {
                isused[i] = true;
                String curNumber = number + input.charAt(i);
                numbers.add(Integer.parseInt(curNumber));
                func(k+1, curNumber, input);
                isused[i] = false;
            }
        }
    }

    boolean isPrime(int number) {
        if (number < 2) {
            return false;
        }
        // 에라토스테네스 체
        for (int i = 2; i <= (int) Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int solution(String input) {
        int answer = 0;
        func(0,"", input);

        for(Integer num : numbers) {
            if(isPrime(num)) {
               answer++;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution("17"));
        System.out.println(solution.solution("011"));
    }
}