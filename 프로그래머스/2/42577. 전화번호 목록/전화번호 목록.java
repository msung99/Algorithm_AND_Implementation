import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> map = new HashMap<>();
        
        // 모든 전화번호를 HashMap 에 추가
        for(int i=0; i<phone_book.length; i++) {
            map.put(phone_book[i], i);
        }
        
        // 모든 전화번호의 substring이 HashMap에 존재하는지 확인
        for(int i=0; i<phone_book.length; i++) {
            for(int j=0; j<phone_book[i].length(); j++) {
                if(map.containsKey(phone_book[i].substring(0, j))) {
                    return false;
                }
            }
        }
        return true;
    }
}