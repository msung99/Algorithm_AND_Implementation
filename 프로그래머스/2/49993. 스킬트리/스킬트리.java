class Solution {
    public static int solution(String skill, String[] skill_trees) {
        int ans = 0;
        for(String skill_tree : skill_trees) {
            String filtered = "";
            for (char c : skill_tree.toCharArray()) {
                if (skill.contains(String.valueOf(c))) {
                    filtered += String.valueOf(c);
                }
            }



            if(skill.startsWith(filtered.toString())) {
                ans++;
            }
        }
        return ans;
    }
}