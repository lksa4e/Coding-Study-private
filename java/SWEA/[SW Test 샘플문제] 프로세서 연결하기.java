import java.io.*;
import java.util.*;

public class Solution {
	static int T, N, length, answer, answer_count;
	static List<Pair> cores;

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;

		T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());

			int[][] map = new int[N][N];
			cores = new ArrayList<Pair>();
			answer = Integer.MAX_VALUE;
			answer_count = 0;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if (map[i][j] == 1) {
						if (i == 0 || j == 0 || i == N - 1 || j == N - 1) // 가장자리에 있는 코어는 무조건 가동됨
							continue;
						cores.add(new Pair(i, j));
					}
				}
			}
			length = cores.size();
			dfs(0, 0, 0, map);
			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.print(sb);
	}

	static void dfs(int core_count, int core_sum, int core_num, int map[][]) {
		if (core_num == length) {
			if (answer_count < core_count) {
				answer_count = core_count;
				answer = core_sum;
			} else if (answer_count == core_count) {
				answer = Math.min(answer, core_sum);
			}
			return;
		}

		int x = cores.get(core_num).x;
		int y = cores.get(core_num).y;

		// 아무것도 안하기
		dfs(core_count, core_sum, core_num + 1, map);
		int flag = 1;

		// 위쪽 확인
		for (int i = 0; i < x; i++) {
			if (map[i][y] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			int[][] copied_map = copymap(map);
			int sum = 0;
			for (int i = 0; i < x; i++) {
				sum++;
				copied_map[i][y] = -1;
			}
			dfs(core_count + 1, core_sum + sum, core_num + 1, copied_map);
		}

		// 오른쪽 확인
		flag = 1;
		for (int i = y + 1; i < N; i++) {
			if (map[x][i] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			int[][] copied_map = copymap(map);
			int sum = 0;
			for (int i = y + 1; i < N; i++) {
				sum++;
				copied_map[x][i] = -1;
			}
			dfs(core_count + 1, core_sum + sum, core_num + 1, copied_map);
		}

		// 아래 확인
		flag = 1;
		for (int i = x + 1; i < N; i++) {
			if (map[i][y] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			int[][] copied_map = copymap(map);
			int sum = 0;
			for (int i = x + 1; i < N; i++) {
				sum++;
				copied_map[i][y] = -1;
			}
			dfs(core_count + 1, core_sum + sum, core_num + 1, copied_map);
		}

		// 왼쪽 확인
		flag = 1;
		for (int i = 0; i < y; i++) {
			if (map[x][i] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			int[][] copied_map = copymap(map);
			int sum = 0;
			for (int i = 0; i < y; i++) {
				sum++;
				copied_map[x][i] = -1;
			}
			dfs(core_count + 1, core_sum + sum, core_num + 1, copied_map);
		}
	}

	static int[][] copymap(int[][] origin) {
		int[][] temp = new int[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp[i][j] = origin[i][j];
		return temp;
	}

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
