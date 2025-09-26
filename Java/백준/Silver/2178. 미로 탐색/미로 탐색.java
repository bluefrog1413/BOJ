import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[105][105];
        int[][] dist = new int[505][505];
        int[] dx = new int[] {1,0,-1,0};
        int[] dy = new int[] {0,1,0,-1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = s.charAt(j)-48;
            }
        }

        Queue<int []> Q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(dist[i][j] == 0&& board[i][j]==1){
                    Q.add(new int[]{i,j});
                    dist[i][j] = 1;
                    while(!Q.isEmpty()){
                        int[] arr = Q.poll();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = dx[dir]+arr[0];
                            int ny = dy[dir]+arr[1];
                            if(nx<0||nx>=n||ny<0||ny>=m) continue;
                            if(board[nx][ny]==0||dist[nx][ny]>0) continue;
                            Q.add(new int[]{nx,ny});
                            dist[nx][ny] = dist[arr[0]][arr[1]]+1;
                        }
                    }
                }
            }
        }
        System.out.println(dist[n-1][m-1]);

    }
}
