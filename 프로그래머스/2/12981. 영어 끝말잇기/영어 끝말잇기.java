import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        answer[0] = 0;
        answer[1] = 0;

        Set<String> set = new HashSet<>();
        set.add(words[0]);

        for(int i=1; i<words.length; i++) {
            char front = words[i].charAt(0);
            char end = words[i-1].charAt(words[i-1].length()-1);

            set.add(words[i]);

            // 이전 단어와 다른 경우라면 or 이전에 등장했던 단어라면
            if(front != end || set.size() == i) {
                // [번호, 자신의 몇 번째에 탈락하는지]d
                answer[0] = (i % n) + 1;
                answer[1] = (i / n) + 1;
                break;
            }
        }

        return answer;
    }
}