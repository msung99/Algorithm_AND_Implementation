import java.util.*;

// 가장 적은 몸무게인 사람 + 가장 큰 몸무게인 사람을 비교하여 경우의 수를 계산한다
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);

        int idx = 0; // 몸무게가 작은 사람의 위치를 나타내는 변수
        
        for(int i=people.length-1; i>=idx; i--) {
            if(people[i] + people[idx] <= limit) {
                answer++;
                idx++;
            } else {
                answer++;
            }
        }

        return answer;
    }
}