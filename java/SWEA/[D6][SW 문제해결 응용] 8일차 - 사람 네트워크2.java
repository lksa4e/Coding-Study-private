import java.io.*;
import java.util.*;

public class Solution1263_김경준 {
	static int N,T,map[][];

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			String arr[] = br.readLine().split(" ");
			N = Integer.parseInt(arr[0]);
			map = new int[N][N];
			int size = 1;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(arr[size++]);
					if(i != j && map[i][j] == 0) map[i][j] = 10001;
				}
			}
			sb.append("#" + tc + " " + floid() + "\n");
		}
		System.out.print(sb);
	}
	static int floid() {
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
		
		int answer = 10001;
		for(int i = 0; i < N; i++) {
			int sum = 0;
			for(int j = 0; j < N; j++) 
				sum += map[i][j];
			
			answer = Math.min(answer, sum);
		}
		
		return answer;
	}
}