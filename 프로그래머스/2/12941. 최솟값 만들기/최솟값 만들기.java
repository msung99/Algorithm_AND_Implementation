import java.util.*;

class Solution {    
    public int solution(int[] arr1, int []arr2) {
        int answer = 0;

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        for(int i=0; i<arr1.length; i++) {
            int cur = arr1[i] * arr2[arr1.length - i - 1];
            answer += cur;
        }

        return answer;
    }
}