/**
* 문제 링크 : https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXsACpHq0FEDFAX6&contestProbId=AV5LyE7KD2ADFAXc&probBoxId=AXsACpHq0FIDFAX6&type=PROBLEM&problemBoxTitle=0804&problemBoxCnt=3
*/
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1873 {
	static int T, H, W, N;  // TC, row, col, N
	static String s, order; // temp, order
	static int x_pos, y_pos, dir; // 탱크위치, 방향
	static int dx[] = { -1, 1, 0, 0 }; // 상 하 좌 우
	static int dy[] = { 0, 0, -1, 1 };
	static char tank[] = { '^', 'v', '<', '>' }; // 방향별 탱크 모습
	static char map[][];  // 지도
	static int answer;

	private static void checkdir() {  //초기 탱크 방향 판별
		if (map[x_pos][y_pos] == '^') {
			dir = 0;
		} else if (map[x_pos][y_pos] == 'v') {
			dir = 1;
		} else if (map[x_pos][y_pos] == '<') {
			dir = 2;
		} else if (map[x_pos][y_pos] == '>') {
			dir = 3;
		}
	}
	
	private static boolean oob(int x, int y) {
		return x < 0 || x >= H || y < 0 || y >= W;
	}

	private static void shoot() {  // dir 방향으로 총알 전진하다가 * 만나면 파괘, 나머지 X
		int tempx = x_pos;
		int tempy = y_pos;
		while (true) {
			tempx += dx[dir];
			tempy += dy[dir];
			if (oob(tempx, tempy)) break;
			if (map[tempx][tempy] == '#') break;
			else if (map[tempx][tempy] == '*') {    // * - 부술수있는벽 
				map[tempx][tempy] = '.';
				break;
			}
		}
	}

	private static void move(char c) {
		// 방향전환
		if (c == 'U')
			dir = 0;
		else if (c == 'D')
			dir = 1;
		else if (c == 'L')
			dir = 2;
		else
			dir = 3;
		int nx = x_pos + dx[dir];
		int ny = y_pos + dy[dir];
		//이동할 수 있으면 - 이동, 이동 불가능하면 (else) - 제자리 방향전환
		if (!oob(nx, ny) && map[nx][ny] == '.') {
			map[x_pos][y_pos] = '.';
			map[nx][ny] = tank[dir];
			x_pos = nx;
			y_pos = ny;
		}else map[x_pos][y_pos] = tank[dir];
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			map = new char[H][W];
			for (int i = 0; i < H; i++) {  // 지도 입력
				s = br.readLine();
				for (int j = 0; j < W; j++) {
					map[i][j] = (s.charAt(j));
					if (map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '<' || map[i][j] == '>') {
						x_pos = i;
						y_pos = j;
					}
				}
			}
			checkdir(); // 초기 방향설정
			
			N = Integer.parseInt(br.readLine());
			order = br.readLine();

			for (int i = 0; i < N; i++) {
				if (order.charAt(i) == 'S') shoot();
				else move(order.charAt(i));
			}
			
			sb.append("#" + tc + " ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					sb.append(map[i][j]);
				}
				sb.append('\n');
			}

			System.out.print(sb.toString());
		}

	}
}
