class Solution {
    int answer = 0;

    void dfs(int k, int total, int[] numbers, int target) {
        if(k == numbers.length) {
            if(total == target) {
                answer++;
            }
            return;
        }

        dfs(k+1, total + numbers[k], numbers, target);
        dfs(k+1, total - numbers[k], numbers, target);
    }

    public int solution(int[] numbers, int target) {
        dfs(0, 0, numbers, target);
        return answer;
    }
}