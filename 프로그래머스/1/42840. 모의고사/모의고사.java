import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;


class Solution {
    int[] arr1 = {1, 2, 3, 4, 5};
    int[] arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
    int[] arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int[] score = {0, 0, 0};

    public int[] solution(int[] answers) {
        for(int i=0; i<answers.length; i++) {
            if(arr1[i%5] == answers[i]) score[0]++;
            if(arr2[i%8] == answers[i]) score[1]++;
            if(arr3[i%10] == answers[i]) score[2]++;
        }

        int max = Math.max(score[0], Math.max(score[1], score[2]));
        List<Integer> answ = new ArrayList<>();
        for(int i=0; i<score.length; i++) {
            if(max == score[i]) {
                answ.add(i+1);
            }
        }

        int[] answer = new int[answ.size()];
        for(int i=0; i<answ.size(); i++) {
            answer[i] = answ.get(i);
        }
        return answer;
    }
}