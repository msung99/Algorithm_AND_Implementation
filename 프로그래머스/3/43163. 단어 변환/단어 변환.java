import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


class Solution {
    boolean canNext(String cur, String next) {
        int diffCnt = 0;
        for(int i=0; i<cur.length(); i++) {
            if(cur.charAt(i) != next.charAt(i)) {
                diffCnt++;
            }
        }
        return diffCnt == 1;
    }

    public int solution(String begin, String target, String[] words) {
        int answer = 0;

        Queue<String> q = new LinkedList<>();
        boolean[] visited = new boolean[words.length];
        q.add(begin);

        while(!q.isEmpty()) {
            int size = q.size();

            for(int j=0; j<size; j++) {
                String cur = q.poll();

                if(cur.equals(target)) {
                    return answer;
                }

                for(int i=0; i<words.length; i++) {
                    boolean canNext = canNext(cur, words[i]);
                    if(!visited[i] && canNext) {
                        visited[i] = true;
                        q.add(words[i]);
                    }
                }
            }
            answer++;
        }

        return 0;
    }
}