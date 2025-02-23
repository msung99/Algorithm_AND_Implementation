

class Solution {
    int convertCnt = 0;
    int deleteCnt = 0;

    // 이진 변환의 횟수와 + 변환 과정에서 제거된 모든 0의 개수
    public int[] solution(String s) {
        int[] answer = new int[2];

        while(!s.equals("1")) {
            String tmp = removeZero(s);
            deleteCnt += removeZeroCount(s, tmp);

            int len = tmp.length();
            s = Integer.toString(len, 2);
            convertCnt++;
        }

        answer[0] = convertCnt;
        answer[1] = deleteCnt;

        return answer;
    }

    private String removeZero(String s) {
        return s.replace("0", "");
    }

    private int removeZeroCount(String s1, String s2) {
        return s1.length() - s2.length();
    }
}

// 110010101001
// 111111      / 00 0 0 00 => 110
// 110