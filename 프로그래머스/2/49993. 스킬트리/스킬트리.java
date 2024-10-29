class Solution {
    public static int solution(String skill, String[] skill_trees) {
        int answer = 0;

        for (String skill_tree : skill_trees) {
            StringBuilder filteredSkills = new StringBuilder();

            // skill_tree에서 skill에 포함된 문자만 순서대로 추출
            for (int i = 0; i < skill_tree.length(); i++) {
                char c = skill_tree.charAt(i);
                if (skill.indexOf(c) != -1) { // skill에 해당 문자가 포함되어 있는지 확인
                    filteredSkills.append(c);
                }
            }

            // 필터링된 스킬 순서가 skill의 앞부분과 일치하는지 확인
            if (skill.startsWith(filteredSkills.toString())) {
                answer++;
            }
        }

        return answer;
    }
}