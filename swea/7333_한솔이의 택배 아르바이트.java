import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
  
public class Solution {
    static int n;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
  
        int tc = Integer.parseInt(br.readLine());
      for(int z=1;z<=tc;z++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            int idx = 0;
            int result = 0;
            for(int i=0; i<n; i++) {
                int t = Integer.parseInt(br.readLine()); // 물건의 무게
                if(t>=50) {
                    result++;
                }else {
                    arr[idx++] = t;
                }
            }
            if(idx==0) {
                sb.append('#').append(z).append(' ')
                        .append(result).append('\n');
                continue;
            }
            Arrays.sort(arr,0,idx);
  
            int t = arr[--idx];
            int sum = t;
            for(int i=0;i<idx;i++) {
                sum+=t;
                if(sum>=50) {
                    t = arr[--idx];
                    sum = t;
                    result++;
                }
            }
            sb.append('#').append(z).append(' ')
                    .append(result).append('\n');
        }// end of tc
        System.out.println(sb);
    }// end of main
}// end of class