import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public static String solution(int[] numbers) {
        // int 배열을 문자열 배열로 변환
        String[] strNumbers = Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .toArray(String[]::new);

        // 문자열 배열을 커스텀 정렬
        Arrays.sort(strNumbers, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                // 두 문자열을 이어붙여 비교
                String order1 = s1 + s2;
                String order2 = s2 + s1;
                return order2.compareTo(order1); // 큰 값이 앞에 오도록 정렬
            }
        });

        // 가장 큰 수가 "0"으로 시작할 경우 "0"을 반환
        if (strNumbers[0].equals("0")) {
            return "0";
        }

        // 정렬된 문자열을 이어붙여 결과 반환
        StringBuilder result = new StringBuilder();
        for (String num : strNumbers) {
            result.append(num);
        }

        return result.toString();
    }
}