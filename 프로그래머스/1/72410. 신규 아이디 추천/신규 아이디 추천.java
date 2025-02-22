class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase(); // 1단계
        new_id = new_id.replaceAll("[^-_.a-z0-9]", ""); // 2단계
        new_id = new_id.replaceAll("[.]{2,}", "."); // 3단계
        new_id = new_id.replaceAll("^[.]|[.]$", "");    // 4단계

        if (new_id.equals("")) {    // 5단계
            new_id += "a";
        }

        if (new_id.length() >= 16) {     // 6단계
            new_id = new_id.substring(0, 15);
            new_id = new_id.replaceAll("[.]$","");
        }

        if (new_id.length() <= 2) {  // 7단계
            while (new_id.length() < 3) {
                new_id += new_id.charAt(new_id.length()-1);
            }
        }
        
        return new_id;
    }
}