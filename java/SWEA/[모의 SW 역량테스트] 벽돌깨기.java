import java.io.*;
import java.util.*;

public class SWEA5656_벽돌깨기 {
	static int T, N, W, H, map[][], answer;
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			map = new int[W][H];
			
			for(int i = 0; i < W; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < H; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			answer = Integer.MAX_VALUE;
			selectCol(0, map);
			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.println(sb);
	}
	
	static int countRemainBlock(int[][] map) {
		int sum = 0;
		for(int i = 0; i < W; i++) {
			for(int j = 0; j < H; j++)
				if(map[i][j] != 0) sum++;
		}
		return sum;
	}
	
	static void selectCol(int cnt, int[][] map) {
		if(cnt == N) {
			answer = Math.min(answer, countRemainBlock(map));
			return;
		}
		for(int i = 0; i < H; i++) {
			int[][] new_map = copymap(map);
			crashAfterFind(new_map, i);
			selectCol(cnt + 1, new_map);
		}
	}
	
	static void crashAfterFind(int[][] map, int col) {
		for(int i = 0; i < W; i++) {
			if(map[i][col] != 0) {
				crash(map, i, col);
				setGravity(map);
				break;
			}
		}
	}
	
	static void setGravity(int[][] map) {
		for(int j = 0; j < H; j++) {
			int flag = W-1;
			for(int i = W-1; i >= 0; i--) {
				if(map[i][j] == 0) continue;
				if(flag == i) {
					flag--;
					continue;
				}
				map[flag--][j] = map[i][j];
				map[i][j] = 0;
			}
		}
	}
	
	static void crash(int[][] map, int x, int y) {
		Queue<int[]> crashedBlock = new ArrayDeque<int[]>();
		crashedBlock.offer(new int[] {x,y, map[x][y]});
		map[x][y] = 0;
		while(!crashedBlock.isEmpty()) {
			int[] cur = crashedBlock.poll();
			int cur_x = cur[0];
			int cur_y = cur[1];
			int cur_size = cur[2];
			
			for(int i = 0; i < 4; i++) {
				int nx = cur_x;
				int ny = cur_y;
				for(int j = 0; j < cur_size - 1; j++) {
					nx += "2110".charAt(i)-'1';
					ny += "1201".charAt(i)-'1';
					if(oob(nx,ny)) continue;
					if(map[nx][ny] > 1) crashedBlock.offer(new int[] {nx, ny, map[nx][ny]});
					map[nx][ny] = 0;
				}
			}
		}
	}
	
	static int[][] copymap(int[][] origin){
		int temp[][] = new int[W][H];
		for(int i = 0; i < W; i++) {
			for(int j = 0; j < H; j++) 
				temp[i][j] = origin[i][j];
		}
		return temp;
	}
	
	static boolean oob(int x, int y) {
		return x < 0 || x >= W || y < 0 || y >= H;
	}
}
