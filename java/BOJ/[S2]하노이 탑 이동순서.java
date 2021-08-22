import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int N;
	static int answer = 0;
	static StringBuilder sb = new StringBuilder();

	// src에서 temp를 거쳐 target으로 N개
	static void solve(int src, int temp, int target, int n) {
		if (n == 1) {
			sb.append(src + " " + target + "\n");
			answer++;
		} else {
			solve(src, target, temp, n - 1);
			sb.append(src + " " + target + "\n");
			answer++;
			solve(temp, src, target, n - 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		solve(1, 2, 3, N);
		System.out.println(answer);
		System.out.print(sb.toString());
		
	}
}
