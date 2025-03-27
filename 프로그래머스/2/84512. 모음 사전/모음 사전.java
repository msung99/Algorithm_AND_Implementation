import java.util.ArrayList;
import java.util.List;

class Solution {
    static String[] words = {"A", "E", "I", "O", "U"};
    List<String> results = new ArrayList<>();

    public void dfs(String curWord) {
        results.add(curWord);
        
        if(curWord.length() == 5) {
            return;
        }

        for(int i=0; i<5; i++) {
            dfs(curWord + words[i]);
        }
    }

    public int solution(String word) {
        int ans = 0;
        dfs("");

        for(int i=0; i<results.size(); i++) {
            if(results.get(i).equals(word)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
}