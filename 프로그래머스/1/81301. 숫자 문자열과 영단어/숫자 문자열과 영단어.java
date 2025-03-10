class Solution {
    static String[] arr = {"zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten"};

    public int solution(String s) {
        for(int i=0; i<arr.length; i++) {
            if (s.contains(arr[i])) {
                s = s.replace(arr[i], String.valueOf(i));
            }
        }
        return Integer.parseInt(s);
    }
}