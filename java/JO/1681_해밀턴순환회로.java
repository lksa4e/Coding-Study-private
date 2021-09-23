import java.io.*;
import java.util.*;

public class JO_1681_해밀턴순환회로 {
	static int T, N, map[][], answer = Integer.MAX_VALUE;
	static boolean visit[];

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		N = Integer.parseInt(br.readLine());
		map = new int[N+1][N+1];
		visit = new boolean[N+1];
		for(int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		permu(1, 0, 1);
		System.out.println(answer);
	}
	static void permu(int before, int sum, int cnt) {
		if(cnt == N) {
			if(map[before][1] != 0) {
				sum += map[before][1];
				answer = Math.min(sum, answer);				
			}
			return;
		}
		
		for(int next = 2; next <= N; next++) {
			if(!visit[next] && map[before][next] != 0) {
				int new_sum = sum + map[before][next];
				if(new_sum < answer) {
					visit[next] = true;
					permu(next, new_sum, cnt + 1);
					visit[next] = false;
				}
			}
		}
	}
}
