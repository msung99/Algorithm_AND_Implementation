import java.util.*;

class Solution {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};

    public static int[] solution(String[][] places) {
        int[] answer = new int[places.length];

        for (int i = 0; i < places.length; i++) {
            answer[i] = bfs(places[i]);
        }
        return answer;
    }

    public static int bfs(String[] place) {
        List<int[]> persons = new ArrayList<>();

        for(int i=0; i<place.length; i++) {
            for(int j=0; j<place[i].length(); j++) {
                if(place[i].charAt(j) == 'P') {
                    persons.add(new int[]{i, j});
                }
            }
        }

        for(int k=0; k<persons.size(); k++) {
            Queue<int[]> q = new LinkedList<>();
            int[][] dist = new int[5][5];

            for(int i=0; i<5; i++) {
                Arrays.fill(dist[i], -1);
            }

            q.add(persons.get(k));
            dist[persons.get(k)[0]][persons.get(k)[1]] = 0;

            while(!q.isEmpty()) {
                int[] cur = q.poll();
                int x = cur[0];
                int y = cur[1];

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) {
                        continue;
                    }

                    if(dist[nx][ny] != -1) {
                        continue;
                    }

                    if(place[nx].charAt(ny) == 'O') {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.add(new int[]{nx, ny});
                    }

                    if(place[nx].charAt(ny) == 'P' && dist[x][y] <= 1) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}
/*
POOOP
OXXOX
OPXPX
OOXOX
POXXP
*/

/*
POOPX
OXPXP
PXXXO
OXXXO
OOOPP
*/

/*
PXOPX
OXOXP
OXPOX
OXXOP
PXPOX
*/