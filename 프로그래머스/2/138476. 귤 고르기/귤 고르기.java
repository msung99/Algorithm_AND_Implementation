import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int sum = 0;
        int answer = 0;

        HashMap<Integer, Integer> dic = new HashMap<>();

        for(int i=0; i<tangerine.length; i++) {
            dic.put(tangerine[i], dic.getOrDefault(tangerine[i], 0) + 1);
        }

        ArrayList<Integer> valueList = new ArrayList<>(dic.values());
        Collections.sort(valueList, Collections.reverseOrder());
        
        for(int value : valueList) {
            // 탐색을 진행하며, 귤의 개수가 k 미만이라면 현재 사용한 특정 크기의 귤의 개수를 카운팅한다.
            if(sum + value < k) {
                sum += value;
                answer++;
            } else {
                // 탐색을 진행하며, 귤의 개수가 k 이상이라면 탐색을 종료하고 카운트한 값을 정답처리한다.
                answer++;
                break;
            }
        }

        return answer;
    }
}