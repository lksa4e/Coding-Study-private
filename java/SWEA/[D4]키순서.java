import java.io.*;
import java.util.*;

public class D4_SWEA5643_키순서 {
	static int T, N, M, map[][];
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			M = Integer.parseInt(br.readLine());
			map = new int[N + 1][N + 1];
			for(int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int small = Integer.parseInt(st.nextToken());
				int big = Integer.parseInt(st.nextToken());
				map[small][big] = 1;
				map[big][small] = -1;
			}
			
			// 플로이드 와샬을 이용해서 전체 관계 구하기
			for(int k = 1; k <= N; k++) {
				for(int i = 1; i <= N; i++) {
					for(int j = 1; j <= N; j++) {
						// i보다 k가 크고, k보다 j가 크면 i보다 j가 크다
						if(map[i][k] == 1 && map[k][j] == 1)
							map[i][j] = 1;
						// i보다 k가 작고, k보다 j가 작으면 i보다 j가 작다 
						if(map[i][k] == -1 && map[k][j] == -1)
							map[i][j] = -1;
					}
				}
			}
			int answer = 0;
			for(int i = 1; i <= N; i++) {
				int sum = 0;
				for(int j = 1; j <= N; j++) {
					if(map[i][j] == 0) sum++; 
				}
				if(sum == 1) answer++; 
			}
			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.println(sb);
	}
}
