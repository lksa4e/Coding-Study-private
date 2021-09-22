import java.io.*;
import java.util.*;

/*
 * G5 - BOJ 2036 치즈
 * BFS를 통해 0,0에서 출발하여 바깥공기를 탐색하고, 치즈를 만나면(바깥공기 접촉 치즈) 지워버림
 */
public class Main1463_김경준 {
	static int row,col, map[][];
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		map = new int[row][col];
		for (int i = 0;  i < row; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < col; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int cheese_num = getCheeseNum(); // 녹이기 작업 이전 치즈값
		int cnt = 0;
		while(cheese_num > 0) {  // 어차피 아래의 break로 중단하지만, 초기 치즈값이 0인 경우를 대비한 while 인자
			int melt_num = melt();
			cnt++;
			if(cheese_num - melt_num == 0) break;  // 만약 이번 녹는작업으로 모든 치즈 사라지면 break;
			cheese_num -= melt_num;
		}
		
		System.out.println(cnt);
		System.out.println(cheese_num);
	}
	
	static int getCheeseNum() {
		int sum = 0;
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(map[i][j] == 1) sum++;
			}
		}
		return sum;
	}
	
	static int melt() {
		Queue<int[]> q = new ArrayDeque<int[]>();
		boolean[][] visit = new boolean[row][col];
		q.offer(new int[] {0, 0});
		visit[0][0] = true;
		
		int cnt = 0;
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int cur_x = cur[0];
			int cur_y = cur[1];
			for(int i = 0; i < 4; i++) {
				int nx = cur_x + ("1201".charAt(i) - '1');
				int ny = cur_y + ("2110".charAt(i)- '1');
				
				if(oob(nx,ny)) continue;
				if(visit[nx][ny]) continue;
				
				if(map[nx][ny] == 0) {
					visit[nx][ny] = true;
					q.offer(new int[] {nx,ny});
				}
				if(map[nx][ny] == 1) {
					visit[nx][ny] = true;
					map[nx][ny] = 0;
					cnt++;
				}
			}
		}
		return cnt;
	}
	static boolean oob(int x, int y) {
		return x < 0 || x >= row || y < 0 || y >= col;
	}
}
