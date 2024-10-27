import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        // Use a HashMap to count occurrences of each participant's name
        HashMap<String, Integer> map = new HashMap<>();
        for (String p : participant) {
            map.put(p, map.getOrDefault(p, 0) + 1);
        }

        // Decrement the count for each name found in completion
        for (String c : completion) {
            map.put(c, map.get(c) - 1);
        }

        // Find the participant whose count is not zero (meaning they didn't complete)
        for (String key : map.keySet()) {
            if (map.get(key) != 0) {
                answer = key;
                break;
            }
        }
        return answer;
    }
}