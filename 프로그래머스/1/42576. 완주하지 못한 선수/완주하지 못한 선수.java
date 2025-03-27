import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> map = new HashMap<>();

        for(String member : participant) {
            map.put(member, map.getOrDefault(member, 0) + 1);
        }

        for(String complete : completion) {
            map.put(complete, map.get(complete)-1);
        }

        String answer = "";
        for(String key : map.keySet()) {
            if(map.get(key) == 1) {
                answer = key;
                break;
            }
        }
        return answer;
    }
}