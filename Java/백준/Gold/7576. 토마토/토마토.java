import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[1005][1005];
        int[][] dist = new int[1005][1005];
        int[] dx = new int[] {1,0,-1,0};
        int[] dy = new int[] {0,1,0,-1};
        int ans = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        Queue<int []> Q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if(board[i][j]==1) Q.add(new int[]{i,j});
            }
        }

        while(!Q.isEmpty()){
            int[] arr = Q.poll();
            for (int dir = 0; dir < 4; dir++) {
                int nx = dx[dir]+arr[0];
                int ny = dy[dir]+arr[1];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(board[nx][ny] == -1 ||board[nx][ny]==1 || dist[nx][ny]!=0&&dist[nx][ny]<=dist[arr[0]][arr[1]]+1) continue;
                Q.add(new int[] {nx,ny});
                dist[nx][ny] = dist[arr[0]][arr[1]]+1;
            }
        }

        boolean clr = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]==0&&dist[i][j]==0) {
                    clr = false;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(ans,dist[i][j]);
            }
        }

        if(clr) System.out.println(ans);
        else System.out.println(-1);

    }
}
