import java.util.Arrays;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        Arrays.sort(reserve);
        Arrays.sort(lost);

        answer = n - lost.length; // 도난 당하지 않은 학생 수

        // 여별 체육복을 가져왔지만 도둑 맞은 경우
        // 다른 학생에게 체육복을 빌려줄 수 없음
        for(int i=0; i<lost.length; i++) {
            for(int j=0; j<reserve.length; j++) {
                if(lost[i] == reserve[j]) {
                    answer++;
                    lost[i] = -1;
                    reserve[j] = -1;
                    break;
                }
            }
        }

        // 도난 당했지만 체육복을 빌릴 수 있는 학생 수
        for(int i=0; i<lost.length; i++) {
            for(int j=0; j<reserve.length; j++) {
                if(lost[i]-1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                    answer++;
                    reserve[j] = -1;
                    break;
                }
            }
        }

        return answer;
    }
}