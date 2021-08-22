import java.io.*;
import java.util.*;

public class Main15683_김경준 {
	static int N, M, answer = Integer.MAX_VALUE, camera_num;
	static ArrayList<Tuple> list = new ArrayList<Tuple>();  // CCTV 리스트
	static int map[][];
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, -1, 0, 1 };
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > 0 && map[i][j] < 6) { // CCTV인 경우 list에 추가
					list.add(new Tuple(i, j, map[i][j]));
				}
			}
		}
		camera_num = list.size(); // 전체 CCTV 개수
		solve(map, 0);
		System.out.print(answer);
	}
	static void get_answer(int[][] arr) {  // 사각지대 개수 카운트
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0)
					sum++;
			}
		}
		answer = Math.min(answer, sum);  // 사각지대 최소개수 구하기
	}
	static void draw(int[][] arr, int x, int y, int sign) {  // CCTV 감시 채우기
		while (true) {
			x += dx[sign];
			y += dy[sign];
			if (oob(x, y)) break;
			if (arr[x][y] == 6) break;
			if (arr[x][y] == 0) arr[x][y] = 7;  // 만약 빈공간이면 감시구역으로 마킹
		}
	}

	static void solve(int[][] arr, int camera_idx) {
		if(camera_idx == camera_num) {  // 모든 CCTV에 대해 수행하였으면 return
			get_answer(arr);
			return;
		}
		
		Tuple current_camera = list.get(camera_idx);
		int x = current_camera.x;
		int y = current_camera.y;
		int num = current_camera.num;
		int[][] temp;  // 다음 dfs로 배열 넘겨주기 위한 배열
		
		switch (num) {
		case 1:
			for(int i = 0; i < 4; i++) {     // 상하좌우 케이스에 대해 dfs
				temp = deepCopy(arr); 
				draw(temp, x, y, i);
				solve(temp, camera_idx + 1);
			}
			break;
		case 2:
			temp = deepCopy(arr);  // 상 하
			draw(temp, x, y, 0);
			draw(temp, x, y, 2);
			solve(temp, camera_idx + 1);
			
			temp = deepCopy(arr);  // 좌우
			draw(temp, x, y, 1);
			draw(temp, x, y, 3);
			solve(temp, camera_idx + 1);
			
			break;
		case 3:
			for(int i = 0; i < 4; i++) {       // 2개씩 묶어서
				temp = deepCopy(arr);
				draw(temp, x, y, i);
				draw(temp, x, y, (i + 1) % 4);
				solve(temp, camera_idx + 1);
			}
			break;
		case 4:
			for(int i = 0; i < 4; i++) {          // 4개 중 1개만 빼고
				temp = deepCopy(arr);
				for(int j = 0; j < 4; j++) {
					if(i != j) draw(temp, x, y, j);
				}
				solve(temp, camera_idx + 1);
			}
			break;
		case 5:
			temp = deepCopy(arr);
			for (int i = 0; i < 4; i++) {         // 4방향 전부
				draw(temp, x, y, i);
			}
			solve(temp, camera_idx + 1);
			break;
		}
	}

	static boolean oob(int x, int y) {
		return x < 0 || x >= N || y < 0 || y >= M;
	}
	static int[][] deepCopy(int[][] original2) {        // 2차원 배열 복사하기 위한 deepcopy
        if(original2 == null) return null;
        int[][] result = new int[original2.length][original2[0].length];
         
        for(int i=0; i<original2.length; i++){
            System.arraycopy(original2[i], 0, result[i], 0, original2[0].length);
        }
         
        return result;
    }
}

class Tuple {  // CCTV 정보 저장
	int x, y, num;
	public Tuple(int x, int y, int num) {
		this.x = x;
		this.y = y;
		this.num = num;
	}
}
