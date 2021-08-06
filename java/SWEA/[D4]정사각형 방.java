/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LtJYKDzsDFAXc
모든 방에 대해, 최대 몇개의 방을 이동할 수 있는지 검사한다.
기존에 탐색하며 거쳐갔던 방은 최대 몇개까지 이동할 수 있는지 알 수 있다. 
시작점에서 최대 이동거리 방까지 result 만큼 이동을 하고,
x, y 좌표의 방까지 cnt 만에 이동을 했을 때 => x,y 좌표에서 최대 이동거리 방까지의 이동거리는 result - cnt + 1 이된다.
따라서 시작점에서 도착지점까지 이동하고 return 하는 과정에서 최대로 이동 가능한 거리를 저장해준다.

그래서 기존에 최대 이동거리가 계산된 곳에 도달하면 dfs를 더이상 돌지 않고 해당 위치부터 도달 위치의 거리값을 더하면서 dfs 횟수를 줄인다.
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class S1861 {
	static int N, T;
	static int map[][];  // 방 정보 저장
	static int arr[][];  // 해당 위치에서 최대로 이동할 수 있는 거리
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	static int result, answer, answer_num;
	private static void solve(int x, int y, int cnt) {
        result = Math.max(result, cnt);
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(map[nx][ny] == map[x][y] + 1) {
				if(arr[x][y] != 0) result = arr[x][y] + cnt;
				else solve(nx,ny,cnt + 1);
			}
		}
		arr[x][y] = result - cnt + 1; // 해당 위치에서 최대로 이동할 수 있는 거리
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			answer = 0;
			map = new int[N+2][N+2];
			arr = new int[N+2][N+2];
			for(int i = 1; i <= N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					map[i][j] = (Integer.parseInt(st.nextToken()));
				}
			}
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= N; j++) {
					result = 0;
					solve(i,j,1);
					if(result > answer) {              // 이전까지의 최대 이동거리보다 더 크다면
						answer_num = map[i][j];           // 해당 이동거리로 index 및 값 갱신
						answer = result;
					}else if (result == answer) {         // 만약 이동거리가 같을 땐 
						if(answer_num > map[i][j]) answer_num = map[i][j];  // 숫자가 작을 경우 갱신
					}
				}
			}
			sb.append("#"+tc+" "+answer_num+" "+answer+"\n");
		}
		System.out.println(sb.toString());
	}
}
