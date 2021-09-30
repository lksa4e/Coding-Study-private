import java.io.*;
import java.util.*;

public class SWEA1953_탈주범검거 {
	static int T, N, M, X, Y, L, map[][][], cnt = 0;
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0-1,1}, visit[][];
	static int test[][];
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			
			cnt = 1;
			map = new int[N][M][4];
			visit = new int[N][M];
			test = new int[N][M];
			int[] temp = {0,0,0,0};
			
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < M; j++) {
					int num = Integer.parseInt(st.nextToken());
					
					Arrays.fill(temp, 0);
					switch(num) {
					case 1: for(int k = 0; k < 4; k++) temp[k] = 1; break;
					case 2: temp[0] = 1; temp[3] = 1; break;
					case 3: temp[1] = 1; temp[2] = 1; break;
					case 4: temp[0] = 1; temp[2] = 1; break;
					case 5: temp[2] = 1; temp[3] = 1; break;
					case 6: temp[1] = 1; temp[3] = 1; break;
					case 7: temp[0] = 1; temp[1] = 1; break;
					}
					for(int k = 0; k < 4; k++)
						map[i][j][k] = temp[k];
				}
			}
			
			for(int i = 0; i < N; i++) Arrays.fill(visit[i], 21);
			visit[X][Y] = 0;
			dfs(X,Y,1);
			sb.append("#" + tc + " " + cnt + "\n");
		}
		System.out.println(sb);
	}
	static void dfs(int x, int y, int count) {
		if(count == L) return;
		for(int i = 0; i < 4; i++) {
			int nx = x + "0112".charAt(i)-'1';
			int ny = y + "1021".charAt(i)-'1';
			
			if(oob(nx,ny)) continue;
			
			if(map[x][y][i] == 1 && map[nx][ny][3-i] == 1) {
				if(visit[nx][ny] > count + 1) {
					if(visit[nx][ny] == 21) cnt++;
					visit[nx][ny] = count + 1;
					dfs(nx, ny, count + 1);
				}
			}
		}
	}
	static boolean oob(int x, int y) {
		return x < 0 || x >= N || y < 0 || y >= M;
	}
}
