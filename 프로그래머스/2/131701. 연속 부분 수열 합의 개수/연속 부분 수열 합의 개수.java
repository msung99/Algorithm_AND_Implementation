import java.util.HashSet;
import java.util.Set;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;

        Set<Integer> set = new HashSet<>();
        for(int i=0; i<elements.length; i++) {
            for(int j=0; j<elements.length; j++) {
                int cur = 0;
                for(int k=j; k<j+i; k++) {
                    cur += elements[k % elements.length];
                }
                set.add(cur);
            }
        }

        return set.size();
    }
}