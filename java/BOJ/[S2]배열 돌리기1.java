import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P16926 {
	static int N,M,R;
	static int[][] arr;
	static int[][] temp;
	static StringBuilder sb = new StringBuilder();
	//회전 함수
	static void spin() {
		temp = new int[N][M];  // 임시 배열에 돌린 결과 저장
		int cnt = 0, size = Math.min(N/2, M/2);
		while(cnt < size) {
			for(int i = N-1-cnt; i > cnt; i--) temp[i][cnt] = arr[i-1][cnt];  // 아래로
			for(int i = M-1-cnt; i > cnt; i--) temp[N-1-cnt][i] = arr[N-1-cnt][i-1]; // 오른쪽
			for(int i = cnt; i < N-1-cnt; i++) temp[i][M-1-cnt] = arr[i+1][M-1-cnt]; // 위로
			for(int i = cnt; i < M-1-cnt; i++) temp[cnt][i] = arr[cnt][i+1]; // 왼쪽
			cnt++;
		}
		arr = temp;  //돌린 결과를 원래 배열로
	}
	static void print() {  //출력
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				sb.append(arr[i][j] + " ");
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i = 0; i < R; i++) spin();
		print();
	}
}