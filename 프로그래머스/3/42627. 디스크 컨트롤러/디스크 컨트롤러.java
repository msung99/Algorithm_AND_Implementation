import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[][] jobs) {

        // 배열을 요청 시작 시점을 기준으로 오름차순 정렬
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);

        // 우선순위큐를 처리 소요시간의 오름차순으로 정렬하도록 기준 설정
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        int answer = 0;
        int jobsIdx = 0;  // jobs 배열의 인덱스
        int count = 0; // 수행된 요청 개수
        int end = 0; // 수행되고난 직후의 시간

        while (count < jobs.length) {
            // 하나의 작업이 완료되는 시점(end)까지 들어온 모든 요청을 큐에 넣음
            while(jobsIdx < jobs.length && jobs[jobsIdx][0] <= end) {
                q.add(jobs[jobsIdx]);
                jobsIdx++;
            }

            // 큐가 비어있다면 작업 완료(end)까지 다시 요청이 들어온다는 의미
            if(q.isEmpty()) {
                end = jobs[jobsIdx][0];
            }

            // 작업이 끝나기 전 (end 이전) 에 들어온 요청 중 가장 수행시간이 짧은 요청부터 수행
            else {
                int[] temp = q.poll();
                answer += temp[1] + end - temp[0];
                end += temp[1];
                count++;
            }
        }

        return (int) Math.floor(answer / jobs.length);
    }
}