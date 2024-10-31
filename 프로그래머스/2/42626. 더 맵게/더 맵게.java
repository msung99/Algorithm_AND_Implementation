import java.util.PriorityQueue;


class Solution {
    public int solution(int[] scoville, int k) {
        int answer = 0;

        PriorityQueue<Integer> q = new PriorityQueue<>();

        for(int i=0; i<scoville.length; i++) {
            q.add(scoville[i]);
        }

        while(q.peek() < k) {
            if(q.size() == 1) {
                return -1;
            }

            int first = q.poll();
            int second = q.poll();
            q.add(first + second*2);
            answer++;
        }

        return answer;
    }
}