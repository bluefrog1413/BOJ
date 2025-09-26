import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int [][]arr = new int[3][4];
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 4; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 0; j < 4; j++) {
                cnt+=arr[i][j];
            }
            if(cnt==0) System.out.println('D');
            else if(cnt==1) System.out.println('C');
            else if(cnt==2) System.out.println('B');
            else if(cnt==3) System.out.println('A');
            else if(cnt==4) System.out.println('E');
        }
    }
}
