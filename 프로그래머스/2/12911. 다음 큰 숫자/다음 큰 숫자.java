class Solution {
    int getOneCnt(int num) {
        int cnt = 0;
        String binNum = Integer.toBinaryString(num);
        for(int i=0; i<binNum.length(); i++) {
            if(binNum.charAt(i) == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    
    public int solution(int n) {
        int answer = 0;
        int cur = n;

        int originCnt = getOneCnt(n);

        while(true) {
            cur++;
            int curCnt = getOneCnt(cur);
            if(curCnt == originCnt) {
                answer = cur;
                break;
            }
        }

        return answer;
    }
}