/**
* 문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PobmqAPoDFAUq
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int N, T;
	static int snail[][];           // 달팽이 맵
	static int dx[] = {0,1,0,-1};   // 우 하 좌 상
	static int dy[] = {1,0,-1,0};
	private static boolean oob(int x, int y) {
		return x <0 || x>= N || y < 0 || y >= N;
	}
	private static void solve() {
		snail = new int[N][N];
		int cnt = 1;
		int x_pos = 0, y_pos = 0, dir = 0;
		while(cnt <= N*N) {                 // n*n 만큼 달팽이 숫자를 모두 채울 때까지
			snail[x_pos][y_pos] = cnt;       // 달팽이 지도 채우기
			int nx = x_pos + dx[dir];        // 다음 예정 좌표
			int ny = y_pos + dy[dir];
			if(oob(nx,ny) || snail[nx][ny] != 0) {  // 다음 예정 좌표가 맵 밖이거나 or 이미 달팽이 숫자 채워져 있을때
				dir = (dir + 1) % 4;                // 방향전환
				x_pos = x_pos + dx[dir];
				y_pos = y_pos + dy[dir];
			}else {
				x_pos = nx;
				y_pos = ny;
			}
			cnt++;
		}
	}
	private static void print(int tc) {  //출력
		System.out.println("#"+ tc);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j <N; j++) {
				System.out.print(snail[i][j] + " ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			solve();
			print(tc);
		}
	}
}
