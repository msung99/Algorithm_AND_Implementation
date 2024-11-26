class Solution {
    public String solution(String s) {
        String[] strNums = s.split(" ");
        int[] nums = new int[strNums.length];

        for(int i=0; i<nums.length; i++) {
            nums[i] = Integer.parseInt(strNums[i]);
        }

        int mx = Integer.MIN_VALUE;
        int mn = Integer.MAX_VALUE;

        for(int i=0; i<nums.length; i++) {
            mx = Math.max(mx, nums[i]);
            mn = Math.min(mn, nums[i]);
        }
    
        return mn + " " + mx;
    }
}