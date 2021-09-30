import java.io.*;
import java.util.*;

public class D4_SWEA1249_보급로 {
	static int T, N, M, answer, map[][];
	static int visit[][];
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			visit = new int[N][N];
			answer = Integer.MAX_VALUE;
			for(int i = 0; i < N; i++) Arrays.fill(visit[i], 999999);
			for(int i = 0; i < N; i++) {
				char[] str = br.readLine().toCharArray();
				for(int j = 0; j < N; j++) {
					map[i][j] = str[j] -'0';
				}
			}
			bfs();
			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.println(sb);
	}
	static void bfs() {
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.offer(new int[]{0, 0, 0});
		visit[0][0] = 0;
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int x = cur[0];
			int y = cur[1];
			int sum = cur[2];
			if(x == N-1 && y == N-1) {
				answer = Math.min(answer, sum);
				continue;
			}
			for(int i = 0; i < 4; i++) {
				int nx = x + "2110".charAt(i)-'1';
				int ny = y + "1201".charAt(i)-'1';
				
				if(oob(nx,ny)) continue;
				if(visit[nx][ny] > sum + map[nx][ny]) {
					visit[nx][ny] = sum + map[nx][ny];
					q.offer(new int[] {nx,ny,sum + map[nx][ny]});
				}
			}
		}
	}	
	static boolean oob(int x, int y) {
		return x < 0 || x >= N || y < 0 || y >=N;
	}
}
