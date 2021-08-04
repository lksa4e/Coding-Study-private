/*
문제 링크 : https://www.acmicpc.net/problem/1654
특정한 자를 랜선의 길이를 정하고 해당 Case에 대해 총 몇개의 조각으로 자를 수 있는지를 검사한다.
이때 K의 범위는 1~10000, N의 범위는 1~10000000 이기 때문에 단순하게 모든 경우의 수를 탐색한다면 시간초과가 난다.
따라서 이분탐색을 통해 자를 기준을 정하도록 한다. 
*
*/
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P1654 {
	static int N, M, left = 1, right = 0, answer = 0;
	static int[] arr;
	static void solve() {
		while(left <= right) {
			int mid = (int)(((long)left + right) / 2);  // 랜선의 길이
			if (mid == 0) return;
			int cnt = 0;
			for(int i = 0; i < N; i++) {
				cnt += arr[i] / mid;
			}
			if(cnt >= M) {
				left = mid + 1;
				answer = Math.max(answer, mid);
			}else {
				right = mid - 1;
			}
		}
	}
	// parametric search -> 이진탐색을 통한 극 값 찾기 --> 나중에
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			right = Integer.max(right, arr[i]);
		}
		solve();
		System.out.print(answer);
	}
}
