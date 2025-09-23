import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] board = new int[505][505];
        boolean[][] vis = new boolean[505][505];
        int[] dx = new int[] {1,0,-1,0};
        int[] dy = new int[] {0,1,0,-1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int ans = 0;
        int MAX = 0;
        Queue<int[]> Q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!vis[i][j]&&board[i][j] ==1){
                    Q.add(new int[]{i,j});
                    vis[i][j] = true;
                    int cnt = 1;
                    ans++;
                    while(!Q.isEmpty()){
                        int[] arr = Q.poll();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = dx[dir]+arr[0];
                            int ny = dy[dir]+arr[1];
                            if(nx<0||nx>=n||ny<0||ny>=m) continue;
                            if(board[nx][ny]==0||vis[nx][ny]) continue;
                            Q.add(new int[]{nx,ny});
                            vis[nx][ny] = true;
                            cnt++;
                        }
                    }
                    MAX = Math.max(MAX,cnt);
                }
            }
        }
        System.out.println(ans);
        System.out.println(MAX);
    }
}
