import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class Solution {
	
	static int tc;
	static int n;
	static double ret;
	static double maxN;
	static double[][] num;
	static int[] visited;
	static Vector<Integer> v;
	
	public static void dfs(double sum, int cnt) {
		if(sum * 100 <= maxN) return;
		if(cnt == n) {
			for(int i=0;i<n;i++) {
				sum *= (double)num[i][v.get(i)] / 100 ;
        	}
        	if(ret <= sum) ret = sum;
        	
			return;
		}
		
		for(int i=0;i<n;i++) {
			if(visited[i] == 1) continue;
			visited[i] = 1;
			v.add(i);
			dfs(sum, cnt + 1);
			visited[i] = 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		tc = Integer.parseInt(br.readLine());
		
        for(int t=1;t<=tc;t++) {
        	n = Integer.parseInt(br.readLine());
        	ret = 0;
        	maxN = 0.0000000001;
        	num = new double[n][n];
        	visited = new int[n];
        	v = new Vector<Integer>();
        	
        	for(int i=0;i<n;i++) {
        		StringTokenizer st = new StringTokenizer(br.readLine());
        		for(int j=0;j<n;j++) {
        			num[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	
        	dfs(1.0, 0);
        	
            System.out.printf("#%d %d\n", t++, ret*100);
        }
	}
}
