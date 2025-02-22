class Solution {
    public int solution(int n) {
        String threeNum = Integer.toString(n, 3);
        String reverse = new StringBuilder(threeNum).reverse().toString();
        return Integer.parseInt(reverse, 3);
    }
}