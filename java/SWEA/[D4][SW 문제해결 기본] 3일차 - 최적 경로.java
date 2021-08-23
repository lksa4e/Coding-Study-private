import java.io.*;
import java.util.*;

public class Solution1247_김경준 {
	static int T, N, answer, office_x, office_y, house_x, house_y;
	static int map[][];
	static boolean visit[];
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][2];
			visit = new boolean[N];
			answer = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			office_x = Integer.parseInt(st.nextToken());
			office_y = Integer.parseInt(st.nextToken());
			house_x = Integer.parseInt(st.nextToken());
			house_y = Integer.parseInt(st.nextToken());
			for(int i = 0; i < N; i++) {
				map[i][0] = Integer.parseInt(st.nextToken());
				map[i][1] = Integer.parseInt(st.nextToken());
			}
			solve(office_x, office_y, 0, 0);
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}
		System.out.print(sb);
	}
	static void solve(int x, int y, int cnt, int dist) {
		if(cnt == N) {
			if(dist + getDist(x,y, house_x, house_y) < answer) {
				answer = dist + getDist(x,y, house_x, house_y);
				return;
			}
		}
		
		if(dist > answer) return;
		
		for(int i = 0; i < N; i++) {
			if(!visit[i]) {
				visit[i] = true;
				solve(map[i][0], map[i][1], cnt + 1, dist + getDist(x, y, map[i][0], map[i][1]));
				visit[i] = false;
			}
		}
		return;
	}
	static int getDist(int x, int y, int nx, int ny) {
		return Math.abs(nx - x) + Math.abs(ny - y);
	}
}
