import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


class Solution {
    boolean[] visited;
    
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
        visited = new boolean[words.length];

        Queue<String> q = new LinkedList<>();
        q.add(begin);

        while(!q.isEmpty()) {
            int size = q.size();

            for(int round=0; round<size; round++) {
                String cur = q.poll();

                if(cur.equals(target)) {
                    return answer;
                }

                for(int i=0; i<words.length; i++) {
                    boolean canNext = canNext(cur, words[i]);
                    if(visited[i] || !canNext) {
                        continue;
                    }
                    visited[i] = true;
                    q.add(words[i]);
                }
            }
            answer++;
        }

        return 0;
    }
}