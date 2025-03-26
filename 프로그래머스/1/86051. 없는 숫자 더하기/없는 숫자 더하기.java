class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int[] ans = new int[10];

        for(int i=0; i<numbers.length; i++) {
            int data = numbers[i];
            ans[data] = 1;
        }

        for(int i=0; i<ans.length; i++) {
            if(ans[i] == 0) {
                answer += i;
            }
        }

        return answer;
    }
}