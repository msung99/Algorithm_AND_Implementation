class Solution {
    int zero = 0;
    int one = 0;

    void func(int size, int[][] arr, int sx, int sy) {
        if(size == 1) {
            if(arr[sx][sy] == 0) {
                zero++;
            } else {
                one++;
            }
            return;
        }

        boolean isSameArea = true;
        int color = arr[sx][sy];
        for(int i=sx; i<sx+size; i++) {
            for(int j=sy; j<sy+size; j++) {
                if(arr[i][j] != color) {
                    isSameArea = false;
                    break;
                }
            }
        }

        if(isSameArea) {
            if(color == 0) {
                zero++;
            } else {
                one++;
            }
        } else {
            int half = size/2;
            for(int i=0; i<2; i++) {
                for(int j=0; j<2; j++) {
                    func(half, arr, sx + half*i, sy + half*j);
                }
            }
        }
    }

    public int[] solution(int[][] arr) {
        int[] answer = new int[2];
        int size = arr.length;
        func(size, arr, 0, 0);
        answer[0] = zero;
        answer[1] = one;
        return answer;
    }
}