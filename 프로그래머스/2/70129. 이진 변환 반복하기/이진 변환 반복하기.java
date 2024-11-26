

class Solution {
    int tryCnt = 0;
    int deleteCnt = 0;

    void calculateZeroCount(String s) {
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '0') {
                deleteCnt++;
            }
        }
    }

    String convertLengthToBinary(String s) {
        int len = s.length();
        return Integer.toBinaryString(len);
    }

    String deleteZeros(String s) {
        return s.replace("0", "");
    }

    public int[] solution(String s) {
        int[] answer = new int[2];
        String cur = s;

        while (!cur.equals("1")) { // "1"이 될 때까지 반복
            calculateZeroCount(cur);        // cur에 따라 동작해야 한다고 가정
            cur = deleteZeros(cur);         // cur을 수정
            cur = convertLengthToBinary(cur); // cur의 길이를 이진수로 변환
            tryCnt++;
        }
        
        answer[0] = tryCnt;
        answer[1] = deleteCnt;
        
        return answer;
    }
}

// 110010101001
// 111111      / 00 0 0 00 => 110
// 110