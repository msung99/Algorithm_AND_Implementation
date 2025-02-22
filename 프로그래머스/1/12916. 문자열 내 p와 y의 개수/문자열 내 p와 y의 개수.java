class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int pCnt = 0;
        int yCnt = 0;

        for(char c : s.toCharArray()) {
            c = Character.toLowerCase(c);

            if(c == 'p') {
                pCnt++;
            } else if(c == 'y') {
                yCnt++;
            }
        }

        if(pCnt != yCnt) {
            answer = false;
        }

        return answer;
    }
}