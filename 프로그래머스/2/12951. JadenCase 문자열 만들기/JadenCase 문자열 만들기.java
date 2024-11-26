class Solution {
    String convert(String s) {
        String front = String.valueOf(Character.toUpperCase(s.charAt(0)));
        String back = s.toLowerCase(); 
        
        return front + back.substring(1, back.length());
    }

    String solution(String s) {
        String answer = "";
        String[] strs = s.split(" ");

        for(int i=0; i<strs.length; i++) {
            String now = strs[i];
            
            if(now.length() == 0) {
    			answer += " ";
    		}
            else {
    			answer += now.substring(0, 1).toUpperCase();
                answer += now.substring(1, now.length()).toLowerCase();
                answer += " ";
            }
        }
    
        if(s.substring(s.length()-1, s.length()).equals(" ")){
    		return answer;
    	}
    	
    	// 맨 마지막 " " 제거하고 answer 반환
        return answer.substring(0, answer.length()-1);
    }
}