class Solution {
    public String solution(String my_string) {
        String answer = "";
        
        for(int i=0; i<my_string.length(); i++) {
            String c = String.valueOf(my_string.charAt(i));
            if(!answer.contains(c)) {
                answer += c;
            }
        }
        return answer;
    }
}