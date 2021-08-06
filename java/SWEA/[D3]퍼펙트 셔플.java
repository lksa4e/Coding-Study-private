/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWGsRbk6AQIDFAVW
짝수인 경우 : 0 ~ N/2 까지 탐색하며 i , i + N/2 를 차례대로 출력
홀수인 경우 : 0 ~ N/2 까지 탐색하며 i, i + N/2 +1 을 차례대로 출력한 후, N/2를 마지막에 붙여준다. 
*/

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class S3499 {
	static int N, T;
	static String[] arr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			arr = new String[N];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) {
				arr[i] = st.nextToken();
			}
			sb.append("#" + tc +" ");
			for(int i = 0; i < N/2; i++) {
				if(N % 2 == 1) {
					sb.append(arr[i] + " " + arr[i+N/2 + 1] + " ");					
				}else {
					sb.append(arr[i] + " " + arr[i+N/2] + " ");					
				}
			}
			if(N % 2 == 1) sb.append(arr[N/2] + "\n");
			else sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}
