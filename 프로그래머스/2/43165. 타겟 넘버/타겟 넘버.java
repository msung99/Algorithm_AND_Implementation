class Solution {
    int ans = 0;
    
    void dfs(int k, int sum, int[] numbers, int target) {
        if(k == numbers.length) {
            if(sum == target) {
                ans++;
            }
            return;
        }
        
        dfs(k+1, sum+numbers[k], numbers, target);
        dfs(k+1, sum-numbers[k], numbers, target);
    }

    public int solution(int[] numbers, int target) {
        dfs(0, 0, numbers, target);
        return ans;
    }
}