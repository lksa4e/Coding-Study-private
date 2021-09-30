import java.io.*;
import java.util.*;

public class G1_BOJ1194_달이차오른다가자 {
	static int N, M, minsick_x, minsick_y;
	static char map[][];
	static boolean visit[][][];
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N+2][M+2];
		visit = new boolean[N+2][M+2][128];
		
		for(int i = 0 ; i < N + 2; i++) Arrays.fill(map[i], '#');
		
		for (int i = 1; i <= N; i++) {
			char[] str = br.readLine().toCharArray();
			for (int j = 1; j <= M; j++) {
				map[i][j] = str[j-1];
				if(map[i][j] == '0') {
					minsick_x = i;
					minsick_y = j;
				}
			}
		}
		
		System.out.println(bfs(minsick_x, minsick_y));
	}
	
	static int bfs(int minsick_x, int minsick_y) {
		Queue<Minsick> q = new ArrayDeque<Minsick>();
		q.offer(new Minsick(minsick_x, minsick_y, 0, 0));
		
		while(!q.isEmpty()) {
			Minsick cur = q.poll();
			int x = cur.x, y = cur.y, count = cur.count, key = cur.key;
			
			if(map[x][y] == '1') return count;
			
			for(int i = 0; i < 4; i++) {
				int nx = x + "2110".charAt(i) -'1';
				int ny = y + "1201".charAt(i) -'1';
				
				if(visit[nx][ny][key]) continue;
				if(map[nx][ny] == '#') continue;
				
				// 문
				if( map[nx][ny] - 'A' >= 0 && map[nx][ny] - 'A' <= 5) {
					int key_num = map[nx][ny] -'A';
					// key 들고있으면
					if((key & 1 << key_num) != 0) {
						visit[nx][ny][key] = true;
						q.offer(new Minsick(nx, ny, count + 1, key));
					}
				}
				// 열쇠
				else if(map[nx][ny] - 'a' >= 0 && map[nx][ny] -'a' <= 5) {
					int key_num = map[nx][ny] -'a';
					int new_key = key | 1 << key_num; // 그냥 key 사용하면 다음 for문에서 key값 틀어짐
					visit[nx][ny][new_key] = true;
					q.offer(new Minsick(nx, ny, count + 1, new_key));
				}
				// 평지
				else {
					visit[nx][ny][key] = true;
					q.offer(new Minsick(nx, ny, count + 1, key));
				}
			}
		}
		return -1;
	}
	static class Minsick{
		int x, y, count, key;
		public Minsick(int x, int y,int count, int key) {
			this.x = x;
			this.y = y;
			this.count = count;
			this.key = key;
		}
	}
}
