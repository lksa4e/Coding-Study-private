import java.io.*;
import java.util.*;

public class Solution3289_서로소집합_김경준 {
	static int T, N, M, parent[];
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			parent = new int[N+1];
			for(int i = 1; i <= N; i++) parent[i] = -1;   // 사이즈를 측정하기 위해 -1로 초기화
			
			sb.append("#" + tc + " ");
			for(int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int sign = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				// 0이면 union
				if(sign == 0) union(a,b);  
				else {  // 1이면 find
					if(find(a) == find(b)) sb.append(1);
					else sb.append(0);
				}
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
	static void union(int a, int b) {
		int ap = find(a);
		int bp = find(b);
		
		if(ap == bp) return;  // 이미 같은 집합이면 return
		
		if(ap < bp) {                   // ap가 bp보다 작으면 -> ap가 사이즈 더 큼
			parent[ap] += parent[bp];   // ap에 bp 붙이고, 
			parent[bp] = a;             // bp의 부모를 a index로
		}else {
			parent[bp] += parent[ap];
			parent[ap] = b;
		}
	}
	static int find(int a) {
		if(parent[a] < 0) return a;
		else return parent[a] = find(parent[a]);  // Path Compression
	}
}
