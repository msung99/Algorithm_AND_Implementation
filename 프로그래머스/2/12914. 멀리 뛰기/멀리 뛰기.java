class Solution {
    static int[] d = new int[2002];
    // d[i] : 칸이 총 i개 있을 때 건너뛸 수 있는 경우의 수
    // d[1] = 1
    // d[2] = 2
    // d[[3] = 3

    public long solution(int n) {
        d[1] = 1;
        d[2] = 2;
        
        for(int i=3; i<=n; i++) {
            d[i] = (d[i-1] + d[i-2]) % 1234567;
        }

        return d[n] % 1234567;
    }
}