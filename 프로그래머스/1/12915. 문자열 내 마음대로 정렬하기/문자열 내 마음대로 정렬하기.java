import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] solution(String[] strings, int i) {

        Arrays.sort(strings, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                // i번째 문자를 기준으로 정렬
                if (s1.charAt(i) != s2.charAt(i)) {
                    return Character.compare(s1.charAt(i), s2.charAt(i));
                } else {
                    // i번째 문자가 같으면 사전순 정렬
                    return s1.compareTo(s2);
                }
            }
        });

        return strings;
    }
}