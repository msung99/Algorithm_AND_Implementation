class Solution {
    public String solution(String s, int n) {
    StringBuilder answer = new StringBuilder();
    char[] arr = s.toCharArray();

    for (char cur : arr) {
        if (!Character.isAlphabetic(cur)) {
            answer.append(cur); // 알파벳이 아닌 경우 그대로 추가
        } else {
            char base = Character.isUpperCase(cur) ? 'A' : 'a'; // 대문자/소문자 구분
            char shifted = (char) ((cur - base + n) % 26 + base); // 26으로 나눈 나머지를 이용해 순환
            answer.append(shifted);
        }
    }
    return answer.toString();
}

}