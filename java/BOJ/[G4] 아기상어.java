import java.io.*;
import java.util.*;

/**
 * G2 BOJ 16236 아기 상어
 * 메모리 : 14744kb 시간 : 164ms
 * 
 */
public class BOJ16236_G4_아기상어 {
	static int N, map[][];
	static int answer = 0; 
	static int shark_size = 2, shark_eat = 0, shark_x, shark_y;
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		map = new int[N+2][N+2];
		for(int i = 0; i < N+2; i++) Arrays.fill(map[i], -1);
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 9) {
					shark_x = i;
					shark_y = j;
				}
			}
		}
		System.out.println(solve());
	}
	
	static int solve() {
		int answer = 0;
		
		while(true) {
			int result = eatClosestFish();
			
			if(result > 0) answer += result;
			else break;
		}
		return answer;
	}
	
	static int eatClosestFish() {
		Queue<int[]> q = new ArrayDeque<int[]>();
		List<int[]> fish = new ArrayList<int[]>();
		boolean[][] visit = new boolean[N+2][N+2];
		int cnt = 0;
		
		q.offer(new int[] {shark_x,shark_y});
		visit[shark_x][shark_y] = true;
		
		while(!q.isEmpty()) {
			int size = q.size();
			cnt++;
			while(size--> 0) {
				int[] shark = q.poll();
				int cur_x = shark[0];
				int cur_y = shark[1];
				
				for(int i = 0; i < 4; i++) {
					int nx = cur_x + "2110".charAt(i)-'1';
					int ny = cur_y + "1201".charAt(i)-'1';
					
					if(map[nx][ny] == -1 || map[nx][ny] > shark_size) continue;
					if(visit[nx][ny]) continue;
					
					if(map[nx][ny] == 0 || map[nx][ny] == shark_size) {
						visit[nx][ny] = true;
						q.offer(new int[] {nx,ny});
					}else {
						fish.add(new int[] {nx,ny});
					}
				}
			}
			
			if(fish.size() > 0) {
				Collections.sort(fish, new Comparator<int[]>() {
					public int compare(int[] o1, int[] o2) {
						if(o1[0] == o2[0]) return o1[1] - o2[1];
						else return o1[0] - o2[0];
					}
				});
				
				int nx = fish.get(0)[0];
				int ny = fish.get(0)[1];
				
				map[shark_x][shark_y] = 0;
				map[nx][ny] = 9;
				
				shark_x = nx;
				shark_y = ny;
				
				if(++shark_eat == shark_size) {
					shark_eat = 0;
					shark_size++;
				}
				return cnt;
			}
		}
		return -1;
	}
}
