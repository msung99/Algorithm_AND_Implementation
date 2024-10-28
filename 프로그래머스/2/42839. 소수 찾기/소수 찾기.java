import java.util.HashSet;
import java.util.Set;

class Solution {
    static Set<Integer> numberList;
    boolean[] isused = new boolean[7];

    void func(int k, String input, String number) {
        if(k > input.length()) {
            return;
        }

        for(int i=0; i<input.length(); i++) {
            if(!isused[i]) {
                isused[i] = true;
                String curNumber = number+input.charAt(i);
                numberList.add(Integer.parseInt(curNumber));
                func(k+1, input, curNumber);
                isused[i] = false;
            }
        }
    }

    int solution(String input) {
        int answer = 0;
        numberList = new HashSet<>();
        func(0, input, "");

        for(Integer num : numberList) {
            if(isPrime(num)) {
                answer++;
            }
        }

        return answer;
    }

    public boolean isPrime(Integer number) {
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
}