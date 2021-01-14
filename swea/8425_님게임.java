import java.util.*;
import java.io.FileInputStream;
 
class Solution
{
    static Scanner sc;
    public static void main(String args[]) throws Exception
    {
        sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();
 
        for(int test_case = 1; test_case <= T; test_case++)
        {
            int sol = solution();
            System.out.println("#" + test_case + " " + sol);
        }
    }
 
    public static int solution() {
        int sol = 0;
        int N = sc.nextInt();
        int[] arr = new int[N];
        int xor = 0;
        for(int i = 0; i < N; i++) {
            arr[i] = sc.nextInt(); 
            xor ^= arr[i];
        }
        for(int i = 0; i < N; i++) {
            int need = xor^arr[i];
            if(need < arr[i]) sol++;
        }
        return sol;
    }
}