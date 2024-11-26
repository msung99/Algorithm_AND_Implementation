class Solution {
    public int solution(int n) {
        int answer = 0;

        for(int st=1; st<=n; st++) {
            int curSum = 0;

            for(int num=st; num<=n; num++) {
                int curRes = curSum + num;

                if(curRes < n) {
                    curSum += num;
                }

                else if(curRes > n) {
                    break;
                }

                else if(curRes == n) {
                    answer++;
                    break;
                }
            }
        }

        return answer;
    }
}