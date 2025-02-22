class Solution {
    public boolean solution(String s) {
        if(isLengthSuccessful(s) && isDigit(s)) {
            return true;
        }
        return false;
    }

    private boolean isDigit(String s) {
        boolean isNum = true;
        for(char c : s.toCharArray()) {
            if(!Character.isDigit(c)) {
                isNum = false;
                break;
            }
        }
        return isNum;
    }

    private boolean isLengthSuccessful(String s) {
        int len = s.length();
        return len == 4 || len == 6;
    }
}