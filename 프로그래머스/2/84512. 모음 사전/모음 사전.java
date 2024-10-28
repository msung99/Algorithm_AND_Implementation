import java.util.ArrayList;
import java.util.List;

class Solution {
    static String[] words = {"A","E","I","O","U"};
    static List<String> list;

    void dfs(int k, String curWord) {
        list.add(curWord);

        if(k == 5) {
            return;
        }

        for(int i=0; i<5; i++) {
            dfs(k+1, curWord+words[i]);
        }
    }

    public int solution(String word) {
        int answer = 0;
        list = new ArrayList<>();

        dfs(0,"");
        int size = list.size();

        for(int i=0; i<size; i++) {
            if(list.get(i).equals(word)) {
                answer = i;
                break;
            }
        }

        return answer;
    }
}