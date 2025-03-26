import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

class Solution {
    public int solution(String before, String after) {
        int answer = 1;
        Map<Character, Integer> map = new HashMap<>();

        for(int i=0; i<before.length(); i++) {
            map.put(before.charAt(i), map.getOrDefault(before.charAt(i), 0) + 1);
        }

        if(before.length() != after.length()) {
            answer = 0;
        }

        for(char c : after.toCharArray()) {
            if(!map.containsKey(c) || map.get(c) == 0) {
                answer = 0;
                break;
            }
            map.put(c, map.get(c) - 1);
        }

        return answer;
    }
}