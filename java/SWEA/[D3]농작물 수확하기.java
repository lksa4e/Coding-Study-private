/**
* 문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1210 {
	static int N, T;
	static String s;
	static int map[][];
	static int answer;

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			for(int i = 0; i < N; i++) {
				s = br.readLine();
				for(int j = 0; j < N; j++) {
					map[i][j] = (s.charAt(j)-'0');
				}
			}
			
			answer = 0;
			// 별찍기 위 방향 삼각형 
			for(int i = 0; i <= N/2; i++) {
				int start = N/2 - i;
				for(int j = start; j < N - start; j++) {
					answer += map[i][j];
				}
			}
			// 별찍기 아래 방향 삼각형
			for(int i = N/2 + 1; i < N; i++) {
				int start = i - N/2;
				for(int j = start; j < N - start; j++) {
					answer += map[i][j];
				}
			}
			System.out.println("#"+tc+" "+answer);
		}
		
	}
}
