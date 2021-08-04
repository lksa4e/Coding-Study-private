/**
* 문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2805 {
	static int N, T;
	static int x_pos, y_pos;
	static int map[][] = new int[100][100];
	static int dir, answer;
	private static boolean oob(int x, int y) {
		return x < 0 || x >= 100 || y < 0 || y >= 100;
	}
	// 위쪽 방향으로 계속 이동, 이동하다가 좌 or 우에 사다리 있으면 그쪽으로 빠지기, 제일 위에 도착하면 stop
	private static void solve() {
		dir = 0; // 방향 위쪽설정
		while(true) {             
			int leftx = x_pos;  //leftx, y -> 왼쪽으로 가는경우
			int lefty = y_pos - 1;
			int rightx = x_pos;  //rightx, y -> 오른쪽으로 가는 경우
			int righty = y_pos + 1;
			if(!oob(leftx,lefty) && map[leftx][lefty] == 1 && dir != 3) { //왼쪽으로 갈 수 있으면 -> 왼쪽으로 이동
				dir = 2;
				x_pos = leftx;
				y_pos = lefty;
			}else if (!oob(rightx,righty) && map[rightx][righty] == 1 && dir != 2) { // 오른쪽으로 갈 수 있으면 -> 오른쪽으로 이동
				dir = 3;
				x_pos = rightx;
				y_pos = righty;
			}else {  // 위로 가야할 때
				x_pos = x_pos - 1;
				dir = 0;
			}
			
			if(x_pos == 0) break;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		for(int tc = 0; tc < 10; tc++) {
			T = Integer.parseInt(br.readLine());
			for(int i = 0; i < 100; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < 100; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if(map[i][j] == 2) {
						x_pos = i;
						y_pos = j;
					}
				}
			}
			solve();
			System.out.println("#"+T+" "+y_pos);
		}
	}
}
