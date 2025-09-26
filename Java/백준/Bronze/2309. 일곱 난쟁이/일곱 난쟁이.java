import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[9];
        boolean[] isused = new boolean[9];
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = Integer.parseInt(st.nextToken());
            sum+=arr[i];
        }

        Arrays.sort(arr);
        for (int i = 0; i < 9; i++) {
            sum-=arr[i];
            isused[i] = true;
            for (int j = i+1; j < 9; j++) {
                sum-=arr[j];
                isused[j] = true;
                if(sum==100){
                    for (int k = 0; k < 9; k++) {
                        if(!isused[k]) System.out.println(arr[k]);
                    }
                    return;
                }
                sum+=arr[j];
                isused[j] = false;
            }
            sum+=arr[i];
            isused[i] = false;
        }
    }
}
