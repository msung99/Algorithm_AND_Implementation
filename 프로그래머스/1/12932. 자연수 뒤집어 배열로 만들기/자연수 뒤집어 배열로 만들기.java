class Solution {
    public int[] solution(long n) {
        String str = String.valueOf(n);
        StringBuilder sb = new StringBuilder(str);

        char[] arr = sb.reverse().toString().toCharArray();
        int[] res = new int[arr.length];
        for(int i=0; i<res.length; i++) {
            res[i] = arr[i] - '0';
        }
        return res;
    }
}